// 编写一个程序，将输入字符串中的字符按如下规则排序。
// 规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
// 如，输入： Type 输出： epTy
// 规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
// 如，输入： BabA 输出： aABb
// 规则 3 ：非英文字母的其它字符保持原来的位置。
// 如，输入： By?e 输出： Be?y
// 注意有多组测试数据，即输入有多行，每一行单独处理（换行符隔开的表示不同行）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str = "";
    while(getline(cin, str))
    {
        // isdigit判断字符char是否为数字
        // isalpha判断字符char是否为英文字母
        // 首先我们得把英文字母挑出来 并且找到它们的index
        vector<string> segment(26);
        int n = str.size();
        for(int i = 0; i < n; ++i)
        {
            if(isalpha(str[i]))
            {
                char ch = tolower(str[i]);
                if(ch >= 'a' && ch <= 'z')
                    segment[ch - 'a'] += str[i];
            }
        }
        string tmp = "";
        for(int i = 0; i < segment.size(); ++i)    tmp += segment[i];
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(isalpha(str[i]))    // print letters
                cout << tmp[count++];
            else    cout << str[i];
        }
        cout << endl;
    }
    return 0;
}