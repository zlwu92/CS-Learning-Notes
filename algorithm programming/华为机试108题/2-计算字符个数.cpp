// 第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。
// 输出描述:
// 输出输入字符串中含有该字符的个数。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "";
    char c;
    getline(cin, str);
    cin >> c;
    int res = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        // 注意大小写
        if(tolower(str[i]) == tolower(c))    ++res;
    }
    cout << res << endl;
    return 0;
}