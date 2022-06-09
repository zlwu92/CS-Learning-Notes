// 颠倒给定的 32 位无符号整数的二进制位。
// 进阶:
// 如果多次调用这个函数，你将如何优化你的算法？
// 把要翻转的数从右向左一位位的取出来，如果取出来的是1，将结果 res 左移一位并且加上1；
// 如果取出来的是0，将结果 res 左移一位，然后将n右移一位即可
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int bitsSize = 31; n != 0; n = n >> 1, --bitsSize)
        {
            ans += (n & 1) << bitsSize;
        }
        return ans;
    }
};