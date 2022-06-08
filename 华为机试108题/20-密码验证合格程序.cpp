// 密码要求:
// 1.长度超过8位
// 2.包括大小写字母.数字.其它符号,以上四种至少三种
// 3.不能有相同长度超2的子串重复
// 说明:长度超过2的子串
// 输入描述:
// 一组或多组长度超过2的子符串。每组占一行
// 输出描述:
// 如果符合要求输出：OK，否则输出NG
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool condition2(string& s)
{
    int count[4] = {0};
    for(int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))    count[0]=1;
        else if(isalpha(s[i]) && tolower(s[i])!=s[i])    count[1]=1;
        else if(isalpha(s[i]) && tolower(s[i])==s[i])    count[2]=1;
        else    count[3]=1;
    }
    int sum = count[0] + count[1] + count[2] + count[3];
    if(sum >= 3)    return true;
    else return false;
}
bool condition3(string& s) // key!
{
    for(int i = 0; i < s.size()-2; ++i)
    {
	    string s1 = s.substr(i,3);
	    string s2 = s.substr(i+1);
	    if(s2.find(s1) != string::npos)    return false;
    }
    return true;
}
int main()
{
    string str;
    while(cin >> str)
    {
        if(str.size()>8 && condition2(str) && condition3(str))    cout << "OK" << endl;
        else    cout << "NG" << endl;
    }
    return 0;
}