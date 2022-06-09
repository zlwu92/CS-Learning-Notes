// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
// 示例 1:
// 输入: "Let's take LeetCode contest"
// 输出: "s'teL ekat edoCteeL tsetnoc" 
// 注意：在字符串中，每个单词由 单个空格 分隔，并且字符串中 不会有任何额外的空格。
class Solution {
public:
    string reverseWords(string s) {
        string res = "", t = "";
        istringstream is(s);
        while (is >> t)
        {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n == 0)  return "";
        // 双指针
        int start = 0, end = 0;
        while(start < n && end < n)
        {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j)   swap(s[i], s[j]);
            start = end + 1;
            end = start;    // 下一个单词
        }
        return s;
    }
};