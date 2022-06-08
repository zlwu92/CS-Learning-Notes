// 实现一个 atoi 函数，使其能将字符串转换成整数。
// 该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 如果超过了整型数的范围，则用边界值替代当前值。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
// 比如 +-1 和 -+1都要返回0！
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int sign = 1; // we need to initialize it to 1
        int i = 0;
        int res = 0;
        while(i < str.size() && str[i] == ' ')  i++;
        if(i == str.size()) return 0; // only contains space
        if(str[i] == '+' || str[i] == '-')
        {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        if(i == str.size()) return 0;
        while(str[i] >= '0' && str[i] <= '9')
        {
            // check if overflow
            if(res > INT_MAX/10 || (res == INT_MAX/10 && str[i]-'0' > 7))   
                return (sign == 1) ? INT_MAX : INT_MIN;
            res = res * 10 + (str[i++] - '0');
        }
        return res * sign;
    }
};


