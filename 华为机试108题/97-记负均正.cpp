// 首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int input, positive = 0, negative = 0, sum = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> input;
            if(input < 0)    negative++;
            else if(input > 0)
            {
                sum += input;
                positive++;
            }
        }
        cout << negative << " " << fixed << setprecision(1) << (double)sum / positive * 1.0f << endl;
    }
    return 0;
}