// 注意多组输入输出！！！！！！
// 输入描述:
// 输入一个整数
// 输出描述:
// 计算整数二进制中1的个数
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        if(n == 0)    count = 0;
        else
        {
            while(n > 0)
            {
                n &= n-1;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}