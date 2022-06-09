// 这里只使用单个block 进行前缀和计算。单个block 最多可组织 1024个thread。
// 对于长度为 length的数组 Input，分配 length个thread，每个thread作为一个计算单元负责一个元素。
// 1. 首先在每个warp内 计算各自的前缀和。使用 __shfl_up_sync(0xFFFFFFFF,val,delta,warp_size)
// 2. 每个 warp计算前缀和后，把warp 最后一个线程（laneId=warp_size-1）的val 加载到 block共享数组，对应于每个warp,share[warpId]=val
// 3. 使用第一个 warp对share[warps]数组计算前缀和
// 4. 选择warpId>=1的warp，其有thread的val+=share[warpId-1]
// 5. 各个thread的 val写入到output的位置。
/**
 * @brief 
 *  这个实验性的 用一个block计算 长度为 length数组的前缀和，Input为长度为n 的输入数组，只保证一个block计算前缀和
 *  output则是长度为n的Inpute 前缀和 pre_sum 前缀和 sum[i]= a[0]+a[1]+a[2]+..a[i]
 * @tparam index_t 
 * @tparam value_t 
 * @tparam warp_size  =32 
 * @param Input 
 * @param Output 
 * @param length 
 */
template<typename index_t,typename value_t,int warp_size=32>
__global__ void pre_sum_block(value_t * Input,value_t *Output,index_t length)
{
    const int thid = blockDim.x*blockIdx.x + threadIdx.x; // 总的线程
    const int tx=threadIdx.x;
    const int wrapId = tx / warp_size;
    const int wraps =SDIV(blockDim.x,warp_size); // wraps<=32
    const int laneId = tx & (warp_size-1);// 取二进制最后五位，是 threadIdx对32取模的结果。

    if(thid>=length) return;
    // 越界
    value_t val = Input[thid]; // 每个线程的 负责一个数据，本地寄存器上
    __shared__ value_t pre_sum_block [32]; // 每个wrap的最后一个前缀和放在上面
    // const int iters = 
    // 计算 wrap内的前缀和
    #pragma unroll 5
    for(int delta=1;delta<warp_size;delta=delta*2) // 因为warp_size=32，否则应该是 delta< log2f(warp_size)
    {
        // 这个函数返回 同一warp内laneId为 (laneId-delta) 的 thread的 val变量值。如果 (laneId-delta)<0，则返回本线程的val值。
	     value_t temp=__shfl_up_sync(0xFFFFFFFF,val,delta,warp_size);
	     if (laneId >=delta)
	         val += temp;
        
    }
    // wrap是隐式同步的，限制每个wrap单独计算了前缀和
    if( laneId == warp_size-1)
    {
        // 一个wrap最后一个数
        pre_sum_block[wrapId]=val;
    }
    // 对shared memory的数求前缀和 ,wraps肯定是少于32的
    __syncthreads();// block内同步

    if(tx<warp_size) // 取第一个wrap对pre_sum_block计算
    {
        value_t warp_share_val = tx<wraps ?  pre_sum_block[tx] :0;
        #pragma unroll 5
        for(int delta=1;delta<warp_size;delta=delta*2) // 因为warp_size=32，否则应该是 delta< log2f(warp_size)
        {
            value_t temp=__shfl_up_sync(0xFFFFFFFF,warp_share_val,delta,warp_size);
            if (laneId >=delta)
                warp_share_val += temp;
        }

        if(tx<wraps) 
            pre_sum_block[tx]= warp_share_val; // 每个wrap最后一个前缀和组成共享数组 的前缀和

    }
    __syncthreads();// block内同步，因为不同的warp要读share_memory
    if(wrapId>=1)  // 这里是 >=
    {
        //取wrap左边一个数
        val+=pre_sum_block[wrapId-1];
    }
    Output[thid]=val;
}
