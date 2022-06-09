// 给定任意两个字符串，相似度 = “编辑距离＋1”的倒数
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string calStringSimilarity(string a,string b)
{
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 0;	//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
    for (int i=1; i<=m; ++i) dp[0][i] = i;
    for (int i=1; i<=n; ++i) dp[i][0] = i;
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            int one = dp[i-1][j] +1, two = dp[i][j-1]+1, three = dp[i-1][j-1];
            if(a[i-1]!=b[j-1])	three += 1;
            dp[i][j] = min(min(one,two),three);
        }
    }
    string res = "1/";
    return res + to_string(dp[n][m]+1);
}
int main()
{
    string a,b;
    while(cin >> a >> b)
        cout << calStringSimilarity(a, b) << endl;
    return 0;
}