// 计算字符串最后一个单词的长度，单词以空格隔开。
// 输入描述:
// 一行字符串，非空，长度小于5000。
// 输出描述:
// 整数N，最后一个单词的长度。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 从后往前遍历
    string str = "";
    getline(cin, str);
    int n = str.size();
    if(n == 0)    return 0;
    int res = 0;
    int i = n - 1;
    while(str[i]!=' ' && i>=0) // 可以用rfind(' ') 获取 位置pos
    {
        ++res;
        --i;
    }
    cout << res << endl;
    return 0;
}
