// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
// 返回 s 所有可能的分割方案。
// 示例:
// 输入: "aab"
// 输出:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
// 递归
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        DFS(s, 0, out, res);
        return res;
    }
    void DFS(string& s, int start, vector<string>& out, vector<vector<string>>& res)
    {
        if(start == s.size())
        {
            res.push_back(out);
            return ;
        }
        for(int i = start; i < s.size(); ++i)
        {
            if(!isPalindrome(s, start, i))  continue;
            // 如果原字符串是 abcd
            // 访问顺序为: a -> b -> c -> d -> cd -> bc -> bcd-> ab -> abc -> abcd
            out.push_back(s.substr(start, i - start + 1));
            DFS(s, i+1, out, res);
            out.pop_back();
        }
    }
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};