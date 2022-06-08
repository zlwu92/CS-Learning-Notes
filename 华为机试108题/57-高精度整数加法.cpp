// 要求编程实现上述高精度的十进制加法。
// 要求实现方法：
// public String add (String num1, String num2)
// 【输入】num1：字符串形式操作数1，如果操作数为负，则num1的前缀为符号位'-'
// num2：字符串形式操作数2，如果操作数为负，则num2的前缀为符号位'-'
// 【返回】保存加法计算结果字符串，如果结果为负，则字符串的前缀为'-'
// 注：
// (1)当输入为正数时，'+'不会出现在输入字符串中；当输入为负数时，'-'会出现在输入字符串中，且一定在输入字符串最左边位置；
// (2)输入字符串所有位均代表有效数字，即不存在由'0'开始的输入字符串，比如"0012", "-0012"不会出现；
// (3)要求输出字符串所有位均为有效数字，结果为正或0时'+'不出现在输出字符串，结果为负时输出字符串最左边位置为'-'。
// 同两个超长整数加法题
// 输入描述:
// 输入两个字符串数字
// 输出描述:
// 输出相加后的结果，string型
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string longStrAdd(string str1, string str2)
{
    size_t str1Length = str1.size();
    size_t str2Length = str2.size();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    string rStr;
    int flag = 0;
    for (int i = 0; i < str1Length; i++)
    {
        int temp = str1[i] - '0' + str2[i] - '0' + flag;
        temp = temp < 10 ?(flag=0, temp) : (flag = 1, temp - 10);
        rStr += (temp+'0');
    }
    for (int j = str1Length; j < str2Length; j++)
    {
        int temp = str2[j] - '0' + flag;
        temp = temp < 10 ? (flag = 0, temp) : (flag = 1, temp - 10);
        rStr += (temp + '0');
    }
    if (flag == 1)  rStr += '1';
    reverse(rStr.begin(), rStr.end());
    return rStr;
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {        
        string res;
        if(str1.size() < str2.size())    res = longStrAdd(str1, str2);
        else    res = longStrAdd(str2, str1);
        cout << res << endl;
    }
    return 0;
}

