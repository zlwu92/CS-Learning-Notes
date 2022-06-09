// 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
// 示例 2:
// 输入: "aaa"
// 输出: 6
// 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
class Solution {
public:
    int countSubstrings(string s) {
        // 以字符串中的每一个字符都当作回文串中间的位置，然后向两边扩散
        // 每当成功匹配两个左右两个字符，结果 res 自增1，然后再比较下一对
        if(s.empty())   return 0;
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            DFS(s, i, i, res);   // for奇回文中心点
            DFS(s, i, i + 1, res);   // for偶回文左右中心点
        }
        return res;
    }
    void DFS(string& s, int i, int j, int& res)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--; // 向两边扩散
            j++;
            res++;
        }
    }
};