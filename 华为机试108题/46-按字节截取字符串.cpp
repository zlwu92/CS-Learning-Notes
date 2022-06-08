// 编写一个截取字符串的函数，输入为一个字符串和字节数，输出为按字节截取的字符串。
// 但是要保证汉字不被截半个，如"我ABC"4，应该截为"我AB"，
// 输入"我ABC汉DEF"6，应该输出为"我ABC"而不是"我ABC+汉的半个"。 
// 输入描述:
// 输入待截取的字符串及长度
// 输出描述:
// 截取后的字符串
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    int num;
    while (cin >> str >> num)
    {
        string res;
        for(int i = 0, count = 0; i < str.size(), count < num; ++i)
        {
            if(str[i]>=0 && str[i]<=255) // 普通字符范围
            {
                res += str[i];
                count++;
            }
            else if(str[i] > 255)
            {
                if(count+2 > num)    break; // 防止出现半个汉字情况
                res += str[i];
                count += 2;
            }
        }
        cout << res << endl;
    }
    return 0;
}
