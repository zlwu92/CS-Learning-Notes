// 将一个字符中所有出现的数字前后加上符号“*”，其他字符保持不变
// public static String MarkNum(String pInStr)
// {
// return null;
// }
// 注意：输入数据可能有多行
// 输入描述:
// 输入一个字符串
// 输出描述:
// 字符中所有出现的数字前后加上符号“*”，其他字符保持不变
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string s = "*";
    while(cin >> str)
    {
        string res;
        for(int i = 0; i < str.size(); ++i)
        {
            if(isdigit(str[i]))
            {
                if(i==0)
                {
                    if(isdigit(str[i+1]))    res += s + str[i];
                    else    res += s + str[i] + s;
                }
                else
                {
                    bool left = isdigit(str[i-1]);
                    bool right = isdigit(str[i+1]);
                    if(left && right)    res += str[i];
                    else if((!left) && right)    res += s + str[i];
                    else if((!right) && left)    res += str[i] + s;
                    else if((!left) && (!right)) res += s + str[i] + s;
                }
            }
            else    res += str[i];            
        }
        cout << res << endl;
    }
    return 0;
}