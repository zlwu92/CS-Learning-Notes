// 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
// 1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），
// 对相同的错误记录（净文件名（保留最后16位）称和行号完全匹配）只记录一条，错误计数增加；
// 2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
// 3、 输入的文件可能带路径，记录文件名称不能带路径。
// 输入描述:
// 一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
// 输出描述:
// 将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
// 示例1
// 输入
// 复制
// E:\V1R2\product\fpgadrive.c   1325
// 输出
// 复制
// fpgadrive.c 1325 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Record
{
    string linenum;
    string file;
    mutable int count;
    Record(string n,string f):linenum(n),file(f),count(1){}
};
bool operator == (const struct Record & X, const struct Record & Y)
{
    return (Y.linenum == X.linenum) && (Y.file == X.file);
}
bool operator != (const struct Record & X, const struct Record & Y)
{
    return  !(X == Y);
}
int main()
{
    string input1, input2;
    vector<Record> records;
    while(cin >> input1 >> input2)
    {
        string tmp = input1.substr(input1.find_last_of("/\\") + 1);
        string file;
        if(tmp.size() > 16)    file = tmp.substr(tmp.size() - 16);
        struct Record r(input2, tmp);
        auto it = find(records.begin(), records.end(), r);
        // 验证将要载入的错误记录是否重复，并执行载入操作
        if(it != records.end())    it->count++;
        else    records.push_back(r);
    }
    int start = (records.size()>8) ? records.size()-8 : 0;
    for(int i = start; i < records.size(); ++i)
    {
        if(records[i].file.size() > 16)    
            records[i].file = records[i].file.substr(records[i].file.size() - 16);
        cout << records[i].file << " "
             << records[i].linenum<< " " << records[i].count << endl;
    }
    return 0;
}