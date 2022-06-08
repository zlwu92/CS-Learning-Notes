// •计算一个数字的立方根，不使用库函数
// 详细描述：
// •接口说明
// 原型：
// public static double getCubeRoot(double input)
// 输入:double 待求解参数
// 返回值:double  输入参数的立方根，保留一位小数
#include <iostream>
#include <cmath>
#include <iomanip> //要用到格式控制符
using namespace std;

int main()
{
    double n;
    while(cin >> n)
    {
//        if(n == 0.0f)    cout << fixed << setprecision(1) << 0.0 << endl;
        double res = 1.0f;
        // 牛顿法    x = x - (f(x)) / f'(x)
        while(fabs(pow(res, 3) - n) > 1e-5)
        {
            res -= (pow(res, 3) - n) / (3 * pow(res, 2));
        }
        cout << fixed << setprecision(1) << res <<endl;
    }
    return 0;
}