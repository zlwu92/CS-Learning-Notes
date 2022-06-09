// 如果统计的个数相同，则按照ASCII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。
// 实现以下接口：
// 输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用）
// 按照统计个数 由多到少 输出统计结果，如果统计的个数相同，则按照 ASII码 由小到大 排序输出
// 清空目前的统计结果，重新统计
// 调用者会保证：
// 输入的字符串以‘\0’结尾。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Record
{
    int count;
    char ch;
    Record(int n, char cc):count(n), ch(cc){}
};
bool operator == (const struct Record & X, const struct Record & Y)
{
    return (Y.ch == X.ch);
}
bool operator != (const struct Record & X, const struct Record & Y)
{
    return  !(X == Y);
}
bool cmp(Record& a,Record& b)
{
    if(a.count != b.count)    return a.count > b.count;// 降序排列
    else    return a.ch < b.ch;
}
int main()
{
    string str;
    while(getline(cin, str))
    {
        vector<Record> records;
        for(int i = 0; i < str.size(); ++i)
        {
            if(isalpha(str[i]) || isdigit(str[i]) || str[i] == ' ')
            {
                struct Record r(1, str[i]);
                auto it = find(records.begin(), records.end(), r);
                if(it != records.end())    it->count++;
                else    records.push_back(r);
            }
        }
        sort(records.begin(), records.end(), cmp);
        for(int i = 0; i < records.size(); ++i)    cout << records[i].ch;
        cout << endl;
    }
    return 0;
}