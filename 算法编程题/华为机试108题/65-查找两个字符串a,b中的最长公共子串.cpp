// 查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        if (a.size() > b.size())	swap(a, b);
        string str_m; // 存储最长公共子串
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i; j < a.size(); j++)
            {
                string temp = a.substr(i, j - i + 1);
                if (int(b.find(temp))<0)	break;
                else if (str_m.size() < temp.size())
                	str_m = temp;
            }
        }
        cout << str_m << endl;
    }
    return 0;
}

//思路：动态规划经典问题，类似于字符串匹配问题，加一个start标记即可，注意将较短子串最先出现的那个输出
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void findMaxCommonStr(string s1,string s2)
{
    if(s1.length()>s2.length())	swap(s1,s2);
    int len1=s1.length(), len2=s2.length();
    int maxLen=0, start=0;
    vector<vector<int> >dp(len1+1,vector<int>(len2+1,0));
    for(int i=1;i<=len1;++i)
    {
        for(int j=1;j<=len2;++j)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    start = i-maxLen; // 记录最长公共子串的起始位置
                }
            }
        }
    }
   cout << s1.substr(start, maxLen) << endl;
}
int main()
{
   string s1,s2;
   while(cin>>s1>>s2)
   {
       findMaxCommonStr(s1,s2);
   }
   return 0;
}