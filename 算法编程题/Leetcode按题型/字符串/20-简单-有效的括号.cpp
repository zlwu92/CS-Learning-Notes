// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。
// 示例 1:
// 输入: "()"
// 输出: true
// 示例 2:
// 输入: "()[]{}"
// 输出: true
// 示例 3:
// 输入: "(]"
// 输出: false
// 示例 4:
// 输入: "([)]"
// 输出: false
// 示例 5:
// 输入: "{[]}"
// 输出: true
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())   return true;
        stack<char> res; // key point!
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                res.push(s[i]);
            }
            else
            {
                if(res.empty())    return false; // 因为除了括号，没有包含其他字符
                if( res.top()!='(' && s[i]==')' || 
                	res.top()!='[' && s[i]==']' || 
                	res.top()!='{' && s[i]=='}')  return false;
                res.pop();
            }
        }
        return res.empty();
    }
};