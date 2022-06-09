// 输入描述:
// 输入一个字符串。
// 输出描述:
// 输出字符串中最长的数字字符串和它的长度。如果有相同长度的串，则要一块儿输出，但是长度还是一串的长度
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int maxLen = 0;
        string tmp;
        string res;
        for(int i = 0; i < str.size(); i++)
        {
            if(isdigit(str[i]))
            {
                tmp += str[i];
                // 先存着备用的，整个一段拿来
                while(isdigit(str[i+1]))    tmp += str[++i];
                if(tmp.size() > maxLen)
                {
                    // 一旦找到更长的，直接替换即可
                    maxLen = tmp.size();
                    res = tmp;
                }
                // 如果有相同长度的串，则要一块儿输出(直接拼接到后面)
                else if(tmp.size() == maxLen)    res += tmp;
            }
            // 每处理完一段要置空
            tmp.clear();
        }
        cout << res << ',' << maxLen << endl;
    }
    return 0;
}