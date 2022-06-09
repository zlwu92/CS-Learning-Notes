// 正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
// 输入描述:
// 输入两个正整数A和B。
// 输出描述:
// 输出A和B的最小公倍数。
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        int k = min(n, m);
        int i = 1;
        for(int j = 2; j <= k; ++j)
        {
            if(n%j==0 && m%j==0)
            {
                i = j;
            }
        }
        cout << n * m / i << endl;
    }
    return 0;
}