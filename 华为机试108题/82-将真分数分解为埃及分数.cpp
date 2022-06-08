// 分子为1的分数称为埃及分数。现输入一个真分数(分子比分母小的分数，叫做真分数)，
// 请将该分数分解为埃及分数。如：8/11 = 1/2+1/5+1/55+1/110。
// 以上其实是数学家斐波那契提出的一种求解埃及分数的贪心算法，准确的算法表述应该是这样的：
// 设某个真分数的分子为a，分母为b;
// 把b除以a的商部分加1后的值作为埃及分数的某一个分母c；
// 将a乘以c再减去b，作为新的a；
// 将b乘以c，得到新的b；
// 重复上面的步骤。
// 判断b%a是否等于0，最后一个分母为b/a，显然是正确的。
// 输入
// 8/11
// 输出
// 1/2+1/5+1/55+1/110
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int pos = str.find('/');
        int n = str.size();
        string s1 = str.substr(0, pos);
        string s2 = str.substr(pos+1);
        // 斐波那契 贪心算法
        int a = stoi(s1); // 分子
        int b = stoi(s2); // 分母
        int tmp = 0;
        int r = b % a;
        if(r == 0) // 整除
        {
            cout << "1/" << b / a << endl;
            continue;
        }
        while(r)
        {
            tmp = b/a + 1;
            cout << "1/" << tmp << "+";
            a = a * tmp - b;
            b = b * tmp;
            r = b % a;
        }
        cout << "1/" << b / a << endl;
        
    }
    return 0;
}