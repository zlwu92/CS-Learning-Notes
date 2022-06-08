// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度
// 输入: "()(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 使用栈
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(') st.push(i); // 记录左括号的index
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                    // 子串要保证连续最长
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                }
                else    start = i + 1; // 前面无效，从下一个重新开始计数
            }
        }
        return res;
    }
};
// 不用额外空间
// 使用了两个变量 left 和 right，分别用来记录到当前位置时左括号和右括号的出现次数，
// 当遇到左括号时，left 自增1，右括号时 right 自增1。
// 当左括号等于右括号的情况，此时就可以更新结果 res
// 一旦右括号数量超过左括号数量了，说明当前位置不能组成合法括号子串，left 和 right 重置为0 
// 对于这种情况 "(()" 时，在遍历结束时左右子括号数都不相等，
// 此时没法更新结果 res，但其实正确答案是2，怎么处理这种情况呢？
// 答案是再反向遍历一遍，采取类似的机制，稍有不同的是此时若 left 大于 right 了，则重置0，这样就可以 cover 所有的情况了
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, left = 0, right = 0, n = s.size();
        for(int i = 0; i < n; ++i)
        {
        	(s[i] == '(') ? left++ : right++;
        	if(left == right)	res = max(res, 2 * right);
        	else if(right > left)	left = right = 0; // 针对类似 ")(" 情况
        }
        // 针对类似 "(()" 情况
        left = right= 0;
        for(int i = n-1; i >= 0; --i)
        {
        	(s[i] == '(') ? left++ : right++;
        	if(left == right)	res = max(res, 2 * left);
        	else if(left > right)	left = right = 0;
        }
        return res;
    }
};