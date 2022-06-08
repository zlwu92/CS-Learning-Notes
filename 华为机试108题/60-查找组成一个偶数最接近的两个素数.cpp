// 任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
// 输入描述:
// 输入一个偶数
// 输出描述:
// 输出两个素数
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n == 2)    return true;
    int k = sqrt(n);
    for(int i = 2; i <= k; ++i)
    {
        if(n%i == 0)    return false;
    }
    return true;
}
int main()
{
    int even;
    while(cin >> even)
    {
        int minus = even-2;
        int r1, r2;
        for(int i = even/2; i >= 2; --i)
        {
            for(int j = even/2; j < even; ++j)
            {
                if((i+j==even) && isPrime(i) && isPrime(j) && minus > j-i)
                {
                    r1 = i;
                    r2 = j;
                    minus = j - i;
                }
            }
        }
        cout << r1 << endl << r2 << endl;
    }
    return 0;
}