// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
// 返回被除数 dividend 除以除数 divisor 得到的商。
// 整数除法的结果应当截去（truncate）其小数部分，
// 例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
// 泰勒展开。
// 这个相当于是2的幂次的展开，任何一个数K可以被表示为
// K = b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n + ...，利用2^n遍历是一种相对于++i的加速！
// 这道题目也是用类似的方式，将divisor不断进行移位，来得到2^n * divisor，然后得到累加倍数2^n，可以得到结果
// 先全部变成正数
// if(abs(dividend) < abs(divisor))， 那么返回0
// 在运算中使用long避免越界
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend), n = labs(divisor);
        long res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n)
        {
            long t = n, p = 1;
            while (m >= (t << 1))
            {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};
