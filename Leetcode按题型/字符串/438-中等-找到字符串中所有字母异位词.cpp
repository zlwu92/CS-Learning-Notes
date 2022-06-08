// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
// 说明：
// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。
// 示例 1:
// 输入:
// s: "cbaebabacd" p: "abc"
// 输出:
// [0, 6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
// 滑动窗口法
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, mm(256, 0);
        for (char c : p) ++mm[c];
        int left = 0, right = 0;
        int m = p.size(), n = s.size();   
        while (right < n)
        {
        	// 如果右边界的字符已经在哈希表中了，说明该字符在p中有出现，
        	// 则 cnt 自减1，然后哈希表中该字符个数自减1，右边界自加1
            if (mm[s[right++]]-- > 0)  --m;
            // 如果此时 cnt 减为0了，说明p中的字符都匹配上了，加入 res
            if (m == 0)   res.push_back(left);
            // 如果此时 right 和 left 的差为p的长度，收缩左窗口
            // 如果最左边字符在哈希表中的个数>=0，说明该字符是p中的字符
            if (right - left == p.size() && mm[s[left++]]++ >= 0)   ++m;
        }
        return res;
    }
};