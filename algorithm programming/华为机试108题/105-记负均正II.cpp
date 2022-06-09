// 从输入任意个整型数，统计其中的负数个数并求所有非负数的平均值，结果保留一位小数
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int x, count1 = 0, count2 = 0;
    double sum = 0.0;
    while(cin >> x)
    {
        if(x < 0)    ++count1;
        else
        {
            ++count2;
            sum += x;
        }
    }
    cout << count1 << endl << fixed << showpoint << setprecision(1) << sum / count2 << endl;
    return 0;
}