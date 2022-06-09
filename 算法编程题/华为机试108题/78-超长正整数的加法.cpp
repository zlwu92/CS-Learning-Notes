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

