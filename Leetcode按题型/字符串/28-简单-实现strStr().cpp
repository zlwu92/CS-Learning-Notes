// 给定一个 haystack 字符串和一个 needle 字符串，
// 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m == 0)    return 0;
        if(m > n)   return -1;
        for(int i = 0; i <= n-m; ++i)
        {
            if(haystack.substr(i, m) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())  return 0;
        int pos = haystack.find(needle);
        return pos;
    }
};
