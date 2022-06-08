// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m)  return false;
        string tt(26, 0), ss(26, 0);
        for(auto ch : t)    tt[ch-'a']++;
        for(auto ch : s)    ss[ch-'a']++;
        if(ss == tt)    return true;
        else return false;
    }
};