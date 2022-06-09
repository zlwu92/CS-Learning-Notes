// 验证给定的字符串是否可以解释为十进制数字。
// 说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。
// 这里给出一份可能存在于有效十进制数字中的字符列表：
// 数字 0-9
// 指数 - "e"
// 正/负号 - "+"/"-"
// 小数点 - "."
// 所有的字符可以分为六大类，空格，符号，数字，小数点，自然底数和其他字符，
// 我们需要五个标志变量，num, dot, exp, sign分别表示数字，小数点，自然底数和符号是否出现，
// numAfterE表示自然底数后面是否有数字
class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            // 当前位置是空格而后面一位不为空格，但是之前有数字，小数点，自然底数或者符号出现时返回false
            if(s[i] == ' ')
            {
                if(i+1 < n && s[i + 1] != ' ' && (num || dot || exp || sign))   return false;
            }
            // 符号前面如果有字符的话必须是空格或者是自然底数，标记sign为true
            else if(s[i] == '+' || s[i] == '-')
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ')    return false;
                sign = true;
            }
            else if(isdigit(s[i])) // 数字：标记num和numAfterE为true
            {
                num = true;
                numAfterE = true;
            }
            // 如果之前出现过小数点或者自然底数，返回false，否则标记dot为true
            else if(s[i] == '.')
            {
                if(dot || exp)  return false;
                dot = true;
            }
            // 果之前出现过自然底数或者之前从未出现过数字，返回false，否则标记exp为true，numAfterE为false
            else if(s[i] == 'e')
            {
                if(exp || !num) return false;
                exp = true;
                numAfterE = false; // 一旦遇到e，后面必须要接数字，可为后面做判断！
            }
            else    return false; // 其他字符：返回false
        }
        return num && numAfterE;
    }
};