// 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。
// 找到并返回可以用这种方式转换的最短回文串。
// 示例 1:
// 输入: "aacecaaa"
// 输出: "aaacecaaa"
// 递归
class Solution {
public:
    string shortestPalindrome(string s) {
        // 使用 双指针 来找出字符串s的最长回文前缀的大概范围，
        // 最长回文前缀是指从开头开始到某个位置为止是回文串
        int i = 0, n = s.size();
        for(int j = n-1; j >= 0; --j)
        {
            if(s[i] == s[j])    ++i;
        }
        // 此时得到的范围 [0, i) 中的子串并不一定就是最大回文前缀，也可能还需要添加字符
        if(i == n)  return s;
        string rest = s.substr(i);
        // 需要再次调用递归函数来填充使其变为回文串，但可以确定的是可以添加最少的字符数让其变为回文串
        // 提取出剩下的字符，翻转一下加到最前面，
        // 而对范围 [0, i) 内的子串再次递归调用本函数，这样，在子函数最终会组成最短的回文串
        reverse(rest.begin(), rest.end());
        return rest + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};