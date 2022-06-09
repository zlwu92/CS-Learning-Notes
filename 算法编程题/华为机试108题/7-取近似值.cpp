// 写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
// 输入描述:
// 输入一个正浮点数值
// 输出描述:
// 输出该数值的近似整数值
#include <iostream>
#include <string>
using namespace std;

int main()
{
    float f;
    while(cin >> f)
    {
        string str = to_string(f);
        int pos = str.find(".");
        int Int = stoi(str.substr(0, pos));
        int res = (str[pos+1] - '0' >= 5) ? Int+1 : Int;
        cout << res << endl;
    }
    return 0;
}