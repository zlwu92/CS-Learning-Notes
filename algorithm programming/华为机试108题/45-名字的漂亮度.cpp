// 给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
// 每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。
// 给出多个名字，计算每个名字最大可能的“漂亮度”。
// 思路：我们可以用一个数组来统计 各个字母 的出现次数count，并且可以巧妙利用 倒序 来进行 乘法 运算
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            string st;
            cin >> st;
            int i, a[26] = {0}, res = 0;
            for (i = 0; i < st.length(); ++i)
            {
                if (st[i] >= 'a' && st[i] <= 'z')
                    a[st[i] - 'a']++;
                else
                    a[st[i] - 'A']++;
            }
            sort(a, a + 26);
            for (i = 25; i >= 0; --i)
                res += a[i] * (i+1);
            cout << res << endl;
        }
    }
    return 0;
}