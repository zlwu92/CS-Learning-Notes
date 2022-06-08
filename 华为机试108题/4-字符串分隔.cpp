// •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
// •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
// 输入描述:
// 连续输入字符串(输入2次,每个字符串长度小于100)
// 输出描述:
// 输出到长度为8的新字符串数组
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "", str2 = "";
    cin >> str1 >> str2;
    int n1 = str1.size();
    int n2 = str2.size();
    for(int i = 0; i < n1; i += 8)
    {
        string base("00000000");
        int l = (i+8 < n1) ? 8 : n1-i;
        // std::copy(start, end, container.begin());
        copy(str1.begin()+i, str1.begin()+i+l, base.begin()); // key
        cout << base << endl;
    }
    for(int i = 0; i < n2; i += 8)
    {
        string base("00000000");
        int l = (i+8 < n2) ? 8 : n2-i;
        copy(str2.begin()+i, str2.begin()+i+l, base.begin());
        cout << base << endl;
    }
    return 0;
}