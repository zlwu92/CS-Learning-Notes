opencl归约算法kernel代码示例：
__kernel void reduce()
{
    const int idx = get_local_id(0);
    FLOAT local sum[256];
    sum[idx] = -MAXFLOAT;
    const int reduce_num = get_local_size(0);//获取工作组中的线程数量

    for (int h = idx; h < total_num; h+=reduce_num) {//将多个工作组的值映射到当前工作组
        FLOAT in = read_input_data(input);
        sum[idx] = max(sum[idx], in);
    }

    barrier(CLK_LOCAL_MEM_FENCE);
    for(int i = reduce_num/2; i > 0; i /= 2){//对当前工作组进行二分归约运算
        if (idx < i)
            sum[idx] = max(sum[idx], sum[idx + i]);
        barrier(CLK_LOCAL_MEM_FENCE);
    }
    if (idx == 0) {
        write_output_data(output, sum[0]);//将sum[0]的值写入输出地址处
    }
}
// 1. Local Memory 基础版
// 如此循环直到局部内存中的数据全部被累加到local memory的0号位置
// 各个work group的索引为0的线程把数据写入global memory
_kernel void reduction(__global float* g_idata, __local float* sdata)
{
    unsigned int tid = get_local_id(0);
    unsigned int i = get_global_id(0);
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
​
    for(unsigned int s=1; s < get_local_size(0); s *= 2)
    {
        // modulo arithmetic is slow!
        if ((tid % (2*s)) == 0) {
            sdata[tid] += sdata[tid + s];
        }
        barrier(CLK_LOCAL_MEM_FENCE);
    }
}
// 总结：
// 优点
// 实现了数据加和的并行
// work group内部累加的时候使用local memory 提升了访存性能
// 缺点
// 每次都使用进入for循环的线程数量的一半， 缺少完整warp运行，即存在线程分支
// 取余操作效率低
// local memory的访问可能存在banck conflict

// 2. Local Memory 优化版
// 注意这次申请的线程数量是基础版的一半!
_kernel void reduction(__global float* g_idata, __local float* sdata)
{
    unsigned int tid = get_local_id(0);
    unsigned int i = get_global_id(0);
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + get_local_size(0) < n) 
        sdata[tid] += g_idata[i+get_local_size(0)];  
​
    barrier(CLK_LOCAL_MEM_FENCE);
​
    // do reduction in shared mem
    for(unsigned int s=get_local_size(0)/2; s>0; s>>=1) 
    {
        if (tid < s) 
        {
            sdata[tid] += sdata[tid + s];
        }
        barrier(CLK_LOCAL_MEM_FENCE);
    }
}
// 先加载一半数据，剩下的一半加载后直接加到前一半数据上，可以有效降低local的消耗和数据加载次数；

// 3. 优化掉不必要的同步
// 思考GPU的运行机制，GPU严格意义上的并行是warp内部的并行，warp之间并不是完全的真正意义的并行，是由先后调度的。
// 我们要利用warp内部线程天然同步的特性，来减少不必要的同步!
_kernel void reduction(__global float* g_idata, __local float* sdata)
{
    unsigned int tid = get_local_id(0);
    unsigned int i = get_global_id(0);
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + get_local_size(0) < n) 
        sdata[tid] += g_idata[i+get_local_size(0)];  
    barrier(CLK_LOCAL_MEM_FENCE);

    // do reduction in shared mem
    #pragma unroll 1
    for(unsigned int s=get_local_size(0)/2; s>32; s>>=1) 
    {
        if (tid < s) 
        {
            sdata[tid] += sdata[tid + s];
        }
        barrier(CLK_LOCAL_MEM_FENCE);
    }
​    // 把最后一个运行的warp从for循环中提取出来展开；这样避免了最后一个warp的同步，也避免了最后一个warp内部的线程分支。
    if (tid < 32)
    {
        if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; }
        if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; }
        if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; }
        if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; }
        if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; }
        if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; }
    }
}

// 4. 循环展开
_kernel void reduction(__global float* g_idata, __local float* sdata)
{
    unsigned int tid = get_local_id(0);
    unsigned int i = get_global_id(0);
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + get_local_size(0) < n) 
        sdata[tid] += g_idata[i+get_local_size(0)];  
    barrier(CLK_LOCAL_MEM_FENCE);

    // do reduction in shared mem
    // blocksize = 1024
    if (blockSize >= 512) { if (tid < 256) { sdata[tid] += sdata[tid + 256]; } barrier(CLK_LOCAL_MEM_FENCE); }
    if (blockSize >= 256) { if (tid < 128) { sdata[tid] += sdata[tid + 128]; } barrier(CLK_LOCAL_MEM_FENCE); }
    if (blockSize >= 128) { if (tid <  64) { sdata[tid] += sdata[tid +  64]; } barrier(CLK_LOCAL_MEM_FENCE); }
​    // 把最后一个运行的warp从for循环中提取出来展开；这样避免了最后一个warp的同步，也避免了最后一个warp内部的线程分支。
    if (tid < 32)
    {
        if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; }
        if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; }
        if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; }
        if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; }
        if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; }
        if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; }
    }
}

// 5. 单线程计算数量优化
_kernel void reduction(__global float* g_idata, __local float* sdata)
{
    unsigned int tid = get_local_id(0);
    unsigned int i = get_group_id(0)*(get_local_size(0)*2) + get_local_id(0);
    unsigned int gridSize = blockSize*2*get_num_groups(0);
    sdata[tid] = 0;
​
    // we reduce multiple elements per thread.  The number is determined by the 
    // number of active thread blocks (via gridDim).  More blocks will result
    // in a larger gridSize and therefore fewer elements per thread
    while (i < n)
    {         
        sdata[tid] += g_idata[i];
        // ensure we don't read out of bounds -- this is optimized away for powerOf2 sized arrays
        if (nIsPow2 || i + blockSize < n) 
            sdata[tid] += g_idata[i+blockSize];  
        i += gridSize;
    }
    barrier(CLK_LOCAL_MEM_FENCE);
​
    // do reduction in shared mem
    if (blockSize >= 512) { if (tid < 256) { sdata[tid] += sdata[tid + 256]; } barrier(CLK_LOCAL_MEM_FENCE); }
    if (blockSize >= 256) { if (tid < 128) { sdata[tid] += sdata[tid + 128]; } barrier(CLK_LOCAL_MEM_FENCE); }
    if (blockSize >= 128) { if (tid <  64) { sdata[tid] += sdata[tid +  64]; } barrier(CLK_LOCAL_MEM_FENCE); }
    
    if (tid < 32)
    {
        if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; }
        if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; }
        if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; }
        if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; }
        if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; }
        if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; }
    }
    
    // write result for this block to global mem 
    if (tid == 0) g_odata[get_group_id(0)] = sdata[0];
}
// 总结：
// 单线程计算的数据越多，local消耗越少，local中数据的读写次数也越少；
// 但是由于单线程计算数量增多，线程数量变少，并行度又有所下降，所以这是一个需要balance，相互妥协来达到最优的策略！



