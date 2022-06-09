// 输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
// 输入描述:
//  输入一个整数（int类型）
// 输出描述:
//  这个数转换成2进制后，输出1的个数
// a[i]=n%2;
// n/=2;
// i++;
// 位运算！
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        while(n > 0)
        {
            n &= n-1; // 删除 1 bit
            count++;
        }
        cout << count << endl;
    }
    return 0;
}