// 输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        int n1 = 0; // 英文字符
        int n2 = 0; // 空格字符
        int n3 = 0; // 数字字符
        int n4 = 0; // 其他字符
        for(int i = 0; i < str.size(); ++i)
        {
            if(isalpha(str[i]))    n1++;
            else if(isdigit(str[i]))    n3++;
            else if(str[i] == ' ')    n2++;
            else    n4++;
        }
        cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    }
    return 0;
}