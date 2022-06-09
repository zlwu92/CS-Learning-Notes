// 输入描述:
// 输入一个非空字符串
// 输出描述:
// 输出第一个只出现一次的字符，如果不存在输出-1
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int n = str.size();
        unordered_map<char, int> cmap;
        bool flag = false;
        for(int i = 0; i < n; ++i)		
		    cmap[str[i]]++;
        int i;
        for(i = 0; i < n; ++i)
        {
            if(cmap[str[i]] == 1)
            {
                flag = true;
                break;
            }
        }
        if(flag == false)    cout << "-1" << endl;
        else cout << str[i] << endl;
    }
    return 0;
}