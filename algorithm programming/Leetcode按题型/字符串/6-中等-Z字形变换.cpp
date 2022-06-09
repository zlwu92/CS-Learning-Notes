// 实现这个将字符串进行指定行数变换的函数
// 输入: s = "LEETCODEISHIRING", numRows = 3，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 输出: "LCIRETOESIIGEDHN"
// 建立一个大小为 numRows 的字符串数组，把之字形的数组整个存进去，然后再把每一行的字符拼接起来
//  ‘之’ 字形的连接位置了，可以发现其实都是在行数区间 [1, numRows-2] 内
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows)   return s;
        string resStr = "";
        int n = s.size();
        vector<string> strVec(numRows);
        int i = 0;
        while(i < n)
        {
            for(int pos = 0; pos < numRows && i < n; ++pos)
            {
                strVec[pos] += s[i++];
            }
            for(int pos = numRows-2; pos >= 1 && i < n; --pos)
            {
                strVec[pos] += s[i++];
            }
        }
        for(auto &a : strVec)   resStr += a;
        return resStr;
    }
};
// 可以得出以下结论：
// 起始下标都是行号
// 第0层和第numRows-1层的下标间距总是step 。
// 中间层的下标间距总是step-2*行数，2*行数 交替。
// 下标不能超过len(s)-1
class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows <= 1)   return s;
        string resStr = "";
        int n = s.size();
        int step = numRows * 2 - 2; // 间距
        for(int i = 0; i < numRows; ++i)
        {
        	int stride = i * 2;
        	int pos = i; // start
        	while(pos < n)
        	{
        		resStr += s[pos];
        		stride = step - stride;
        		pos += (i==0 || i==numRows-1) ? step : stride;
        	}
        }
        return resStr;
	}
};