// 输入描述:
// 输入一个字符串
// 输出描述:
// 返回有效密码串的最大长度(最长回文子串)
// 求最长回文子串
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s;
    while(cin >> s)
    {
        const int n = s.size();
        if(n <= 1)	return -1;
        int maxLen = 0;
        for(int i = 1; i < n; i++)
        {
            // 寻找以i-1,i为中点偶数长度的回文
            int low = i-1, high = i;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                low--;
                high++;
            }
            // // high - low - 1 = (high-1) - (low-1) + 1
            if(high - low - 1 > maxLen)	maxLen = high - low - 1;
            // 寻找以i为中心的奇数长度的回文
            low = i - 1; high = i + 1;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                low--;
                high++;
            }
            if(high - low - 1 > maxLen)	maxLen = high - low - 1;
        }
        cout << maxLen << endl;
    }
    return 0;
}

