//鸡翁、鸡母、鸡雏分别为x, y, z 三个变量。
//x+y+z=100
//5x+3y+z/3=100
//确定x即可算出y和z，若y和z为非负整数，则为有效结果，输出。
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        for (int x = 0; x <= 100/5; x++)
        {
            double y = (200 - 14 * x) / 8.0;
            double z = 100 - y - x;
            if (y == int(y) && y >= 0 && z >= 0)
                cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}