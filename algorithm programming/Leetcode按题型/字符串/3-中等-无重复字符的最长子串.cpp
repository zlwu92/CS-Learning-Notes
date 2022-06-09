// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
// 框架法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口法
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        while(right < s.size())
        {
            char c = s[right];
            right++;
            window[c]++;
            // 判断左侧窗口是否要收缩
            while(window[c] > 1) // 开始存在重复元素
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            // 不论该次是否重复，需要随时更新res，
            // 而当重复时进入上面当while中res反而不会被更新，因为该次长度一定比前面小！
            res = max(res, right-left);
        }
        return res;
    }
};
// 使用 HashMap 来建立字符和其出现位置之间的映射
// 维护了一个 滑动窗口，窗口内的都是没有重复的字符，需要尽可能的扩大窗口的大小
// 窗口的右边界就是当前遍历到的字符的位置，为了求出窗口的大小，需要一个变量 left 来指向滑动窗口的左边界
// 1. 如果当前遍历到的字符从未出现过，那么直接扩大右边界
// 2. 如果之前出现过，那么就分两种情况，在或不在滑动窗口内，如果不在滑动窗口内，当前字符可以加进来
// 3. 如果在的话，就需要先在滑动窗口内去掉这个已经出现过的字符
// 4. 建立一个 HashMap，建立每个字符和其最后出现位置之间的映射
//执行用时:32 ms	内存消耗:8.5 MB
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> map; // {character, index}
        int length = 0;
        int left = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(map.count(s[i]) && map[s[i]] > left)
            {
                left = m[s[i]];
            }
            map[s[i]] = i;  // 保存每个字符和其最后出现位置之间的映射
            length = max(length, i - left); // update if needed
        }
        return length;
    }
};
//执行用时:12 ms	内存消耗:7.7 MB
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// 用vector的好处是不用像之前的 HashMap 一样要查找当前字符是否存在映射对
		vector<int> map(128, -1); // ASCII 表共能表示 256 个字符，由于键盘只能表示 128 个字符
		int length = 0;
        int left = -1;
        for(int i = 0; i < s.size(); ++i)
        {
        	left = max(left, map[s[i]]);
        	length = max(length, i - left);
        	map[s[i]] = i;        	
        }
        return length;
	}
};

// 3. 无重复字符的最长子串
// 159. 至多包含两个不同字符的最长子串
// 340. 至多包含 K 个不同字符的最长子串
// 485. 最大连续1的个数
// 487. 最大连续1的个数 II
// 1004. 最大连续1的个数 III
// 424. 替换后的最长重复字符
// 76. 最小覆盖子串
// 100. 长度为 K 的无重复字符子串
// 567. 字符串的排列