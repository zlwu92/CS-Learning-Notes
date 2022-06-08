// 假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 
// 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
// 最后的误差判断是小数点6位
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double n;
    while(cin >> n)
    {
        cout << fixed << setprecision(6)
             << n * (1 + 0.5*2 + 0.25*2  + 0.125*2 + 0.0625*2) * 1.0f << endl;
        cout << fixed << setprecision(6) << n / pow(2, 5)*1.0f << endl;
    }
    return 0;
}