// 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
// 如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
// 如果不存在最后一个单词，请返回 0 。
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if(n == 0)   return 0;
        int res = 0;
        int i = n - 1;
        while(i>=0 && s[i]==' ')    --i;
        while(i>=0 && s[i]!=' ')
        {
            ++res;
            --i;
        }        
        return res;
    }
};