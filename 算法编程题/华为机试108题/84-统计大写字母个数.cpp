// 输入描述:
// 输入一个String数据
// 输出描述:
// 输出string中大写字母的个数
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int count = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if( isalpha(str[i]) && (str[i]!=tolower(str[i])) )    count++;
        }
        cout << count << endl;
    }
    return 0;
}