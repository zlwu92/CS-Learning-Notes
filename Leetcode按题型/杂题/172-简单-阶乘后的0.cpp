// 给定一个整数 n，返回 n! 结果尾数中零的数量。
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        // 此题即便为找出 0~n 中 5 的个数
        while (n)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};