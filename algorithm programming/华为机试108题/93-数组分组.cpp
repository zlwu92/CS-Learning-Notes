// 编写一个函数，传入一个int型数组，返回该数组能否分成两组，
// 使得两组中各元素加起来的和相等，
// 并且，所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），
// 能满足以上条件，返回true；不满足时返回false。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string int2BinaryString(int n)
{
    string res;
    while(n)
    {
        switch(n%2)
        {
            case 0:    res += '0';
            case 1:    res += '1';
            default: continue;
        }
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool judgeSum(vector<int>& a, int target)
{
    int n = pow(2, a.size()); // 总组合数
    for(int i = 0; i < n; i++)
    {
        // int to Binary string
        string str = int2BinaryString(i);
        int sum = 0;
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == '1')    sum += a[j];
            else    continue;
        }
        if(sum == target)    return true;
    }
    return false;
}
int main()
{
    int n;
    while(cin >> n)
    {
        int input;
        int sum3 = 0, sum5 = 0, sum = 0;
        vector<int> v3, v5, v;
        // 1.将输入的数字进行分组（%3==0&&%5！=0的为一组，%5==0的为一组，剩余为第三组）
        // 2.假设第一组的总和是sum3，第二组sum5，第三组sum
        for(int i = 0; i < n; ++i)
        {
            cin >> input;
            if(input%3==0 && input%5!=0)
            {
                sum3 += input;
                v3.push_back(input);
            }
            else if(input%5 == 0)
            {
                sum5 += input;
                v5.push_back(input);
            }
            else
            {
                sum += input;
                v.push_back(input);
            }
        }
        if(v.size() == 0)
        {
            if(sum3 == sum5)    cout << "true" << endl;
            else    cout << "false" << endl;
        }
        else
        {
            int minus = sum3 - sum5;
            if(minus != 0)
            {
                v.push_back(minus);
                sum += minus;
            }
            if(sum%2 != 0)    cout << "false" << endl;
            else if(judgeSum(v, sum/2))    cout << "true" << endl;
            else    cout << "false" << endl;
        }
    }
    return 0;
}