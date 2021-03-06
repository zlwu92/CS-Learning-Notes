// 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 被读作  "one 1"  ("一个一") , 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
// 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
// 注意：整数序列中的每一项将表示为一个字符串。
class Solution {
public:
    string countAndSay(int n) {
        // 就是对于前一个数，找出相同元素的个数，把个数和该元素存到新的 string 里
        if(n <= 0)  return "";
        string res = "1";
        while(n>1)
        {
            string tmp = "";
            for (int i = 0; i < res.size(); ++i)
            {
                int count = 1;
                while(i+1<res.size() && res[i]==res[i+1])
                {
                    count++;
                    i++;
                }
                tmp += to_string(count) + res[i];
            }
            res = tmp;
            n--;
        }        
        return res;
    }
};