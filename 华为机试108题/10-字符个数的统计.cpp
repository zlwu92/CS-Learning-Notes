// 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。
// 不在范围内的不作统计。注意是不同的字符
// 输入描述:
// 输入N个字符，字符在ACSII码范围内。
// 输出描述:
// 输出范围在(0~127)字符的个数。
#include <iostream>
#include <string>
#include <unordered_set> // 可装重复任意元素
using namespace std;

int main()
{
    string str = "";
    while(cin >> str)
    {
        int res = 0;
        unordered_set<char> chset;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i]<127 && str[i]>0 && chset.find(str[i])==chset.end())
            {
                res++;
                chset.insert(str[i]);
            }
        }
        cout << res << endl;
    }
    
    return 0;
}