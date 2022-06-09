// 输入描述:
// 先输入字典中单词的个数，再输入n个单词作为字典单词。
// 输入一个单词，查找其在字典中兄弟单词的个数
// 再输入数字n
// 输出描述:
// 根据输入，输出查找到的兄弟单词的个数
// 输入
// 3 abc bca cab abc 1
// 输出
// 2
// bca
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isBrother(string& a, string& b)
{
    if(a == b)    return false; // 兄弟单词 不能是 相同单词
    if(a.size() != b.size())    return false;
    string tmpa(a.begin(), a.end());
    string tmpb(b.begin(), b.end());
    sort(tmpa.begin(), tmpa.end());
    sort(tmpb.begin(), tmpb.end());
    return tmpa == tmpb;
}
int main()
{
    int n;
    while(cin >> n)
    {
        vector<string>input(n);
        for(int i = 0; i < n; ++i)    cin >> input[i];
        sort(input.begin(), input.end()); // 因为是字典，一定要排序！！
        string target = "";
        cin >> target;
        int k;
        cin >> k;
        int count = 0;
        vector<string> res;
        for(int i = 0; i < input.size(); ++i)
        {
            if(isBrother(input[i], target))
            {
                count++;
                res.push_back(input[i]);
            }
        }
        cout << count << endl;
        if(k <= count)    cout << res[k-1] << endl;
    }
    return 0;
}