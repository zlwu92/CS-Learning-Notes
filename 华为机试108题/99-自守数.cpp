// 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数
// 接口说明
// 功能: 求出n以内的自守数的个数
// 输入参数：
// int n
// 返回值：
// n以内自守数的数量。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            string str1 = to_string(i);
            string str2 = to_string(i*i);
            int len1 = str1.size();
            int len2 = str2.size();
            if(str1 == str2.substr(len2-len1))    count++;
        }
        cout << count << endl;
    }
    return 0;
}