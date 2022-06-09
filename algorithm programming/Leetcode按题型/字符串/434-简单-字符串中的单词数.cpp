class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == ' ') continue; // 连续的空格
            res++;
            while(i < n && s[i]!=' ')   ++i; // 连续的字母
        }
        return res;
    }
};