// 给定一个字符串，逐个翻转字符串中的每个单词
class Solution {
public:
    string reverseWords(string s) { // "  hello world!  "
        reverse(s.begin(), s.end()); // 先整体反转
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin)
        {
            if (s[begin] != ' ') //找到了下一个单词字符串的起点
            {
                if (pos != 0) //单词后放一个空格做间隔
                {
                    s[pos++] = ' ';
                }
                int end = begin; // "  !dlrow olleh  "
                while (end < n && s[end] != ' ')  //读到单词，前移，填充多余的空格位置
                {
                    s[pos++] = s[end++];
                } // "!dlrowow olleh  "
                reverse(s.begin()+pos - (end - begin), s.begin()+pos); //局部反转回来
                // "world!ow olleh  "
                begin = end;
            }
        }
        s.erase(s.begin() + pos, s.end()); //末尾可能有多余空格
        return s;
    }
};
