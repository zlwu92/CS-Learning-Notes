// 请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
// 沿着各自边缘线从左上角走到右下角，总共有多少种走法，
// 要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
#include <iostream>
using namespace std;

int getCount(int n, int m)
{
    if(n==1 && m==1)    return 2;
    if(n == 1)    return getCount(1, m-1) + 1;
    if(m == 1)    return getCount(n-1, 1) + 1;
    return getCount(n-1, m) + getCount(n, m-1);
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        int res = getCount(n, m);
        cout << res << endl;
    }
    return 0;
}