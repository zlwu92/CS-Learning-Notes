// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 最后的数是该数字范围内所有的数的左边共同的部分
        // n就这样每次去掉最低位的1
        while(m < n)
        {
            n &= n-1;
        }
        return n;
    }
};