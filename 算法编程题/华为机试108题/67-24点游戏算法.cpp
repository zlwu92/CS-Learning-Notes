// 问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
// 输入：
// 4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
// 输出：
// true or false
#include<iostream>
#include<vector>
using namespace std;
bool is24(vector<double> a, int target, double result)
{
    if(a.empty())
    {
        return result == target;
    }
    for(int i = 0; i < a.size(); ++i)
    {
        vector<double> b(a);
        b.erase(b.begin() + i); // 每次弹出一个元素进行计算
        if(is24(b, target, result + a[i]) || is24(b, target, result - a[i]) || 
           is24(b, target, result * a[i]) || is24(b, target, result / a[i]) )
            return true;
    }
    return false;
}
int main()
{
    vector<double> a(4,0);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3]) // 7 2 1 10 -> 7*2 + 1*10
    {
        if(is24(a, 24, 0))    cout << "true" << endl;
        else    cout << "false" << endl;
    }
    return 0;
}