__global__ void transpose1(const real *A, real *B, const int N)
{
    const int nx = blockIdx.x * blockDim.x + threadIdx.x;
    const int ny = blockIdx.y * blockDim.y + threadIdx.y;
    if (nx < N && ny < N)
    {
        B[nx * N + ny] = A[ny * N + nx];
    }
}
分析：对A的read是顺序的，但对B的write不是顺序的。


__global__ void transpose2(const real *A, real *B, const int N)
{
    const int nx = blockIdx.x * blockDim.x + threadIdx.x;
    const int ny = blockIdx.y * blockDim.y + threadIdx.y;
    if (nx < N && ny < N)
    {
        B[ny * N + nx] = A[nx * N + ny];
    }
}
分析：对A的read是不是顺序的，但对B的write是顺序的。
但是2还是比1性能要好，因为从pascal架构开始，编译器会对read做优化，调用的时候缓存加载函数 __ldg()读取全局内存，缓解影响。

__global__ void transpose3(const real *A, real *B, const int N)
{
    const int nx = blockIdx.x * blockDim.x + threadIdx.x;
    const int ny = blockIdx.y * blockDim.y + threadIdx.y;
    if (nx < N && ny < N)
    {
        B[ny * N + nx] = __ldg(&A[nx * N + ny]);
    }
}
在maxwell和kepler架构的GPU中，需要显示的调用 __ldg()函数才能达到效果。

有 bank 冲突的
__global__ void transpose1(const real *A, real *B, const int N)
{
    __shared__ real S[TILE_DIM][TILE_DIM];
    int bx = blockIdx.x * TILE_DIM;
    int by = blockIdx.y * TILE_DIM;

    int nx1 = bx + threadIdx.x;
    int ny1 = by + threadIdx.y;
    if (nx1 < N && ny1 < N)
    {
        // 这里无bank冲突
        S[threadIdx.y][threadIdx.x] = A[ny1 * N + nx1];
    }
    __syncthreads();

    int nx2 = bx + threadIdx.y;
    int ny2 = by + threadIdx.x;
    if (nx2 < N && ny2 < N)
    {
        // 这里同一个warp中的32个线程对应共享内存中跨度为32的数据，则刚好访问同一个bank中的32个数据，导致32路bank冲突！
        B[nx2 * N + ny2] = S[threadIdx.x][threadIdx.y];
    }
}
分析：
对于bank宽度为4 bytes的架构，共享内存数组中的连续128字节内容分摊到32个bank的某一层，每个bank负责4 bytes 的内容；
对于一个长度为128的float共享内存数组来说，每个bank分摊了4个在地址上相差了128字节的数据；
每一层的32个bank对应32个连续数组元素；每个bank有32层数据；

注意：只要同一个warp内多个线程不同时访问同一个bank中不同层的数据，则对共享内存的访问就只需要一次memory transaction；
而当同一warp内的多个线程访问同一个bank中的不同层数据时，就会发生 bank冲突！！！

无 bank 冲突的
__global__ void transpose2(const real *A, real *B, const int N)
{
    __shared__ real S[TILE_DIM][TILE_DIM + 1]; // 通常，通过加padding的方式改变共享内存数组大小，来消除或者缓解bank冲突
    int bx = blockIdx.x * TILE_DIM;
    int by = blockIdx.y * TILE_DIM;

    int nx1 = bx + threadIdx.x;
    int ny1 = by + threadIdx.y;
    if (nx1 < N && ny1 < N)
    {
        S[threadIdx.y][threadIdx.x] = A[ny1 * N + nx1];
    }
    __syncthreads();

    int nx2 = bx + threadIdx.y;
    int ny2 = by + threadIdx.x;
    if (nx2 < N && ny2 < N)
    {
        B[nx2 * N + ny2] = S[threadIdx.x][threadIdx.y];
    }
}