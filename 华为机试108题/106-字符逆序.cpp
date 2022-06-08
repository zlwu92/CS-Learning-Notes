// 将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。 如：输入“I am a student”，输出“tneduts a ma I”。 
// 输入参数：
// inputString：输入的字符串
// 返回值：
// 输出转换好的逆序字符串
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "";
    while(getline(cin, str))
    {
        for(int i = str.size()-1; i >= 0; --i)
        {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}