// 写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
// 输入描述:
// 输入N个字符
// 输出描述:
// 输出该字符串反转后的字符串
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "";    
    while(cin >> str) // getline(cin,line)
    {
        for(int i = str.size()-1; i >= 0; --i)
        {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;    
}