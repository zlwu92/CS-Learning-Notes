// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
// 示例：
// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"
// 说明：
// 如果 S 中不存这样的子串，则返回空字符串 ""。
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。
// 框架法
class Solution {
public:
    string minWindow(string s, string t) {
        // 用map记录窗口的字符和需要凑齐的字符
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;
        // 使用 left 和 right 变量初始化窗口的两端
        int left = 0, right = 0;
        // 表示窗口中满足 need 条件的字符个数，
        // 如果 valid 和 need.size()相等，则说明窗口已经完全覆盖了串T
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX; 
        while(right < s.size())
        {
            // 开始滑动，加入数据
            char c = s[right];
            right++;
            // 进行窗内数据的更新
            if(need.count(c)) // 如果当前字符恰好是需要覆盖的字符
            {
                window[c]++;
                if(window[c] == need[c])    valid++;
            }
            // 判断左侧窗口是否要收缩
            while(valid == need.size())
            {
                // 更新最小覆盖长度
                if(right-left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                // 进行窗内数据的更新
                if(need.count(d))
                {
                    if(window[d] == need[d])    valid--;
                    window[d]--;
                }
            }
        }
        // 返回最小覆盖子串
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// 滑动窗口算法的思路是这样：
// 1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，
// 把索引左闭右开区间 [left, right) 称为一个「窗口」。
// 2、我们先不断地增加 right 指针扩大窗口 [left, right)，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。
// 3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right)，
// 直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。
// 4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。
// 这个思路其实也不难，**第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解。

