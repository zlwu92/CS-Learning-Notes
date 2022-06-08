// 给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。
// 需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
// 示例 1:
// 输入: "bcabc"
// 输出: "abc"
// 示例 2:
// 输入: "cbacdcbc"
// 输出: "acdb"
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 先建立一个哈希表来统计每个字母出现的次数，
        // 还需要一个visited数字来纪录每个字母是否被访问过
        int m[256] = {0}, visited[256] = {0};
        // 一开始给结果字符串res中放个"0"，就是为了在第一次比较时方便
        // ‘0’的ASCII码要小于任意一个字母的，所以不会有问题
        string res = "0";
        for (auto a : s) ++m[a];
        for (auto a : s)
        {
            m[a]--;
            if(visited[a])  continue;
            // 如果没访问过，我们和结果中最后一个字母比较，
            // 如果该字母的ASCII码小并且结果中的最后一个字母在哈希表中的值不为0(说明后面还会出现这个字母)，
            // 那么我们此时就要在结果中删去最后一个字母且将其标记为未访问
            while(a < res.back() && m[res.back()])
            {
                visited[res.back()] = 0;
                res.pop_back();
            }
            // 然后加上当前遍历到的字母，并且将其标记为已访问
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
};