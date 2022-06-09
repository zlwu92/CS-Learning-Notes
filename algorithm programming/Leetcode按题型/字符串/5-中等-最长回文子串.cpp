// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案
// 方法一（暴力解法）不采用！
// 方法二（中心扩散）枚举所有的「回文中心」并尝试「扩展」，直到无法扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度，求出最大值
class Solution {
public:
    string longestPalindrome(string& s) {
        if(s.size()<=1) return s;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1, length1] = expandAroundCenter(s, i, i);
            auto [left2, right2, length2] = expandAroundCenter(s, i, i+1);
            if(length1 > end-start)
            {
                start = left1;
                end   = right1;
            }
            if(length2 > end-start)
            {
                start = left2;
                end   = right2;
            }
        }
        return s.substr(start, end-start+1);
    }
    tuple<int, int, int> expandAroundCenter(string& s, int left, int right)
    {
        while(left>=0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left+1, right-1, right-left-2}; // 注意返回时回退一步
    }
};
// 方法三（动态规划）
// 维护一个二维数组 dp，其中 dp[i][j] 表示字符串区间 [i, j] 是否为回文串
// dp[i, j] = 1  if i == j
//          = s[i] == s[j]     if j = i + 1
//          = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size(), dp[n][n] = {0}, left = 0, len = 1;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};
// 方法四（Manacher 算法）
// i       0 1 2 3 4 5 6 7 8 9 10 11 12
// arr[i]  # c # a # b # b # a #  f  #
// p[i]    1 2 1 2 1 2 5 2 1 2 1  2  1
// 1. 预处理，做法是在每一个字符的左右都加上一个特殊字符，比如加上 '#'
// 2. 定义一个辅助数组int[] p，p的长度与arr等长，p[i]表示以arr[i]字符为中心的最长回文半径
// 3. 原回文子串的长度 = 修改后回文子串半径-1，即int maxLength = p[i]-1 (偶回文)
// 4. 计算最长回文子串起始索引
// 5. 偶回文的情况下，可以满足i减最长半径，而奇回文却会下标越界
// 6. 在转换后的字符串前面再加一个字符，解决下标越界的问题，$'字符，尾部再加一个不会重复出现的字符，比如'@'
// 7. 结论：最长回文子串的起始索引int index = (i - p[i])/2
// 8. 计算p数组
// i       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// arr[i]  $ # c # a # b # b # a  #  f  #  @ 
// p[i]      1 2 1 2 1 2 5 2 1 2  1  2  1

class Solution {
public:
    string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 1; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};