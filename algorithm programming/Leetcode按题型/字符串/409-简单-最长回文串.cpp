// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
// 示例 1:
// 输入:
// "abccccdd"
// 输出:
// 7
// 解释:
// 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
class Solution {
public:
    int longestPalindrome(string s) {
        // 问题转化为求偶数个字符的个数
        bool isOdd = false;
        int res = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); ++i)   m[s[i]]++;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(it->second % 2 == 1)
            {
                res += it->second-1;
                isOdd = true; // 只要有奇数次的字符出现，就可以构造 奇回文！(可以理解为在构造的时候奇回文包含了偶回文)
            }
            else    res += it->second;
        }
        return isOdd ? res + 1 : res;
    }
};