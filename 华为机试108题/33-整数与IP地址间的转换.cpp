// 原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
// 一个长整数。
// 举例：一个ip地址为10.0.3.193
// 每段数字             相对应的二进制数
// 10                   00001010
// 0                    00000000
// 3                    00000011
// 193                  11000001
// 组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。
// 的每段可以看成是一个0-255的整数，需要对IP地址进行校验
// 输入描述:
// 输入 
// 1 输入IP地址
// 2 输入10进制型的IP地址
// 输出描述:
// 输出
// 1 输出转换成10进制的IP地址
// 2 输出转换后的IP地址
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    unsigned int n, a, b, c, d;
    char ch;    
    while (cin >> a >> ch >> b >> ch >> c >> ch >> d) 
    {
        cout << (a << 24 | b << 16 | c << 8 | d) << endl; // ip to int
        cin >> n;
        // 0x000000ff(16进制) = 00000000 00000000 00000000 11111111(2进制)
        // 0x0000ff00(16进制) = 00000000 00000000 11111111 00000000(2进制)
        // 0x00ff0000(16进制) = 00000000 11111111 00000000 00000000(2进制)
        // 0xff000000(16进制) = 11111111 00000000 00000000 00000000(2进制)
        cout << ((n & 0xff000000) >> 24) << '.'
             << ((n & 0x00ff0000) >> 16) << '.'
             << ((n & 0x0000ff00) >> 8) << '.'
             << (n & 0x000000ff) << endl; // int to ip
    }
    return 0;
}