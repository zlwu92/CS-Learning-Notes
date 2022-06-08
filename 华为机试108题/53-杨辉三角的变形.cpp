//             1

//          1  1  1

//       1  2  3  2  1

//    1  3  6  7  6  3  1

// 1  4  10 16 19  16 10  4  1
// 以上三角形的数阵，第一行只有一个数1，
// 以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
// 求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
// 纯找规律
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n <= 2)    cout << -1 << endl;
        else if(n%2 == 1)    cout << 2 << endl; // 奇数行 规律固定
        else if(n%4 == 0)    cout << 3 << endl;
        else if(n%4 == 2)    cout << 4 << endl;
    }
    return 0;
}

// 动态规划，递归
// 思路：1.找规律，发现，如果用数组表示的话，第1行的1并不是在最左边，而是在第n个元素位置（n代表行号）
//      2.第n行的元素的第一个和最后一个是要提前赋值为1.其他行的元素，除第一个外，按照公式
//      a[i][j]=a[i][j-1]+a[i][j]+a[i][j+1];
#include<iostream>
#include<vector>
using namespace std;
void printYH(int n)
{
     
    vector<vector<int> > a(n, vector<int>(2*n-1, 0));
    a[0][n-1] = a[n-1][0] = a[n-1][2*n-2] = 1; // boundray condition
    if(n < 2)
    {
        cout << "-1" << endl;
        return ;
    }
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < 2*n-2; ++j)
            a[i][j] = a[i-1][j] + a[i-1][j-1] + a[i-1][j+1];
    // 输出    
    for(int i = 0; i < 2*n-1; ++i)
    {
        if(a[n-1][i]!=0 && (a[n-1][i]%2==0))
        {
            cout<< i+1 << endl;
            return ;
        }
    }
    return ;                   
}
int main()
{
    int n;
    while(cin >> n)
    {
        printYH(n);
    }
    return 0;
}