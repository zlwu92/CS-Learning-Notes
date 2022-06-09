#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int judgeSubString(string& s)
{
    int n = s.size();
    if(n == 0)    return -1;
    int digitCount = 0;
    int alphaCount = 0;
    for(int i = 0; i < n; ++i)
    {
        if(isalpha(s[i]))    alphaCount++;
        else if(isdigit(s[i]))    digitCount++;
        else    return -1;
    }
    if(alphaCount == n || digitCount == n)    return -1;
    int maxLen = 2;
    for(int i = 0; i < n-1; ++i)
    {
        if(isalpha(s[i]))
        {
            int j = i+1;
            int count = 1;
            while(j < n && isdigit(s[j]))
            {
                ++count;
                ++j;
            }
            if(count > maxLen)    maxLen = count;
        }
        else if(isdigit(s[i]))
        {
            int j = i+1;
            int count = 1;
            bool isContainAlpha = false;
            while(j < n && !isalpha(s[j]))
            {
                ++count;
                ++j;
                if(isalpha(s[j]) && isdigit(s[j+1]) && isContainAlpha == false)
                {
                    isContainAlpha = true;
                    ++count;
                    ++j;
                }
            }
            if(isContainAlpha == false)    ++count;
            if(count > maxLen)    maxLen = count;
        }
    }
    return maxLen;
}
int main()
{
    string s;
    while(cin >> s)
    {
        int res = judgeSubString(s);
        cout << res << endl;
    }
    return 0;
}
