// 实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
// 输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
// 注意每个输入文件有多组输入，即多个字符串用回车隔开
// 输入描述:
// 字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。
// 输出描述:
// 删除字符串中出现次数最少的字符后的字符串
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int n = str.size();
        vector<int> count(26, 0);
        for(int i = 0; i < n; ++i)
        {
            count[str[i]-'a']++;
        }
        int min = n;
        for(int i = 0; i < n; ++i)
        {
            if(count[str[i]-'a'] < min)
                min = count[str[i]-'a'];
        }
        for(int i = 0; i < n; ++i)
        {
            if(count[str[i]-'a'] > min)
                cout << str[i];
        }
        cout << endl;
    }
    return 0;
}