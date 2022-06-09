// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。
// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
// 动态规划，时间太长
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

// 双指针贪心
// 本题难点在于处理星号的匹配，用iStar和jStar表示星号在s和p中匹配的位置，初始值为-1，
// i和j表示当前匹配的位置，匹配过程如下：
// 如果s和p中字符匹配，则分别自增i和j
// 否则如果p中当前字符为星号，则标记iStar和jStar，同时自增j
// 否则如果iStar >= 0，表示之前匹配过星号，因为星号可以匹配任意字符串，所以继续递增i，同时移动j为jStar下一个字符
// 否则返回false
// 如果星号之前出现过，可以强行续一波命，比如 s = "aa" 和 p = "*c"，
// 当发现 s[1] 和 p[1] 无法匹配时，但是好在之前 p[0] 出现了星号，把 s[1] 交给 p[0] 的星号去匹配。
// 至于如何知道之前有没有星号，这时就能看出 iStar 的作用了，
// 因为其初始化为 -1，而遇到星号时，其就会被更新为i，只要检测 iStar 的值，就能知道是否可以使用星号续命。
// 虽然成功续了命，匹配完了s中的所有字符，但是之后还要检查p串，
// 此时没匹配完的p串里只能剩星号，不能有其他的字符，将连续的星号过滤掉，如果j不等于p的长度，则返回 false
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0;
        int iStar = -1, jStar = -1;
        while (i < m)
        {
            if (j < n && (s[i] == p[j] || p[j] == '?'))
            {
                ++i;
                ++j; // i，j向后顺移
            }
            else if (j < n && p[j] == '*') // 记录如果之后序列匹配不成功时， i和j需要回溯到的位置
            {
                iStar = i;
                jStar = j++;
            }
            // 发现字符不匹配且没有星号出现 但是istar>0 说明可能是*匹配的字符数量不对 这时回溯
            else if (iStar >= 0) // p[j]!='*' && s[i]!=p[j]
            {
            	// i回溯到istar+1 因为上次从s串istar开始对*的尝试匹配已经被证明是不成功的（不然不会落入此分支） 
            	// 所以需要从istar+1再开始试 同时inc istar 更新回溯位置
                i = ++iStar;
                // j回溯到jstar+1 重新使用p串*后的部分开始对s串istar（这个istar在上一行已经inc过了）位置及之后字符的匹配 
                j = jStar + 1;
            }
            else	return false; // 若之前星号从没出现过，即iStart == -1，那么就直接跪
        }
        while (j < n && p[j] == '*')	++j; // 去除多余星号
        return j == n; // 看是否还有多余非'*'尾巴
    }
};