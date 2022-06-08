// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
class Solution {
public:
    int firstUniqChar(string s) {
        // 用哈希表
        unordered_map<char, int> m;
        // 先遍历一遍，填充map
        for(char c : s) ++m[c];
        for(int i = 0; i < s.size(); ++i)
        {
            if(m[s[i]] == 1)   return i;
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        int arrCnt[26] = {0} ;
        for(auto cha : s)   arrCnt[cha - 'a']++;            
        for(int i = 0;i<s.size();i++)
        {
            if(arrCnt[s[i] - 'a']==1)   return i;
        }
        return -1;
    }
};
