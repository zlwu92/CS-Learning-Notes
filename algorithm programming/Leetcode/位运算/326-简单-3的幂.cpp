// 给定一个整数，写一个函数来判断它是否是 3 的幂次方
// 进阶：
// 你能不使用循环或者递归来完成本题吗？
class Solution {
public:
    bool isPowerOfThree(int n) {
        // n 是 3 的幂次 <==> log3n = log10n / log103 is an integer!
        // 判断数字a是否为整数，我们可以用 a - int(a) == 0 来判断
        return (n > 0 && log10(n)/log10(3) - (int)(log10(n)/log10(3)) == 0);
    }
};