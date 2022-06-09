// 若两台主机的IP地址分别与它们的子网掩码相 “&” 后的结果相同，则说明这两台主机在同一子网中。
// 示例：
// I P 地址　 192.168.0.1
// 子网掩码　 255.255.255.0
// 转化为二进制进行运算：
// I P 地址　11010000.10101000.00000000.00000001
// 子网掩码　11111111.11111111.11111111.00000000
// AND运算
//  　　　　11000000.10101000.00000000.00000000
// 转化为十进制后为：
//  　　　　192.168.0.0
// I P 地址　 192.168.0.254
// 子网掩码　 255.255.255.0
// 转化为二进制进行运算：
// I P 地址　11010000.10101000.00000000.11111110
// 子网掩码　11111111.11111111.11111111.00000000
// AND运算
// 　　　　　11000000.10101000.00000000.00000000
// 转化为十进制后为：
// 　　　　　192.168.0.0
#include <iostream>
#include <string>
using namespace std;
string tens2BinString(unsigned int n)
{
    string str = "";
    for(int i = 7; i >= 0; --i)
    {
        if(n & (1<<i))    str += "1";
        else    str += "0";
    }
    return str;
}
int main()
{
    unsigned int a, b, c, d;
    unsigned int a1, b1, c1, d1;
    unsigned int a2, b2, c2, d2;
    unsigned char ch;
    
    while(cin >> a >> ch >> b >> ch >> c >> ch >> d) // mask
    {
        int res;
        cin >> a1 >> ch >> b1 >> ch >> c1 >> ch >> d1;
        cin >> a2 >> ch >> b2 >> ch >> c2 >> ch >> d2;
        string str1 = tens2BinString((a1 & a)) + 
                      tens2BinString((b1 & b)) + 
                      tens2BinString((c1 & c)) + 
                      tens2BinString((d1 & d));
        string str2 = tens2BinString((a2 & a)) + 
                      tens2BinString((b2 & b)) + 
                      tens2BinString((c2 & c)) + 
                      tens2BinString((d2 & d));
        if(str1 == str2)    res = 0;
        else if(str1 != str2)    res = 2;
        cout << res << endl;
    }
    return 0;
}