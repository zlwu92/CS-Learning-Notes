// 在命令行输入如下命令：
// xcopy /s c:\ d:\，
// 各个参数如下： 
// 参数1：命令字xcopy 
// 参数2：字符串/s
// 参数3：字符串c:\
// 参数4: 字符串d:\
// 请编写一个参数解析程序，实现将命令行各个参数解析出来。
// 解析规则： 
// 1.参数分隔符为空格 
// 2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。
// 比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，
// 第3个参数应该是字符串C:\program files，而不是C:\program，
// 注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
// 3.参数不定长 
// 4.输入由用例保证，不会出现不符合要求的输入 
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> split(string& str, char del)
{
    stringstream ss(str);
    vector<string> res;
    string tmp;
    while(getline(ss, tmp, del))    res.push_back(tmp);
    return res;
}
int main()
{
    string str;
    while(getline(cin, str))
    {
        vector<string> tmp = split(str, ' ');
        vector<string> res;
        for(int i = 0; i < tmp.size(); ++i)
        {
            if(tmp[i].find('"') != string::npos)
            {
                string s = tmp[i];
                int j=i+1;
                // 寻找对应的半边引号 ”
                for(; j < tmp.size(); ++j)
                {
                    s = s + ' ' + tmp[j];
                    if(tmp[j].find('"') != string::npos)    break;
                }
                // 去引号
                s.erase(remove(s.begin(), s.end(), '"'), s.end());
                res.push_back(s);
                i = j;
            }
            else    res.push_back(tmp[i]);
        }
        cout << res.size() << endl;
        for(auto r : res)    cout << r << endl;
    }
    return 0;
}