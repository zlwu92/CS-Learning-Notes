// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 示例：
// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]
// 对于这种列出所有结果的题首先还是考虑用递归 Recursion 来解
// 如果在某次递归时，左括号的个数大于右括号的个数，
// 说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现 ')(' 这样的非法串，所以这种情况直接返回，不继续处理。
// 如果 left 和 right 都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回
// 如果以上两种情况都不满足，若此时 left 大于0，则调用递归函数，注意参数的更新，若 right 大于0，则调用递归函数，同样要更新参数
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)  return {};
        if(n == 1)  return {"()"};        
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
    void generate(int lnum, int rnum, string tmp, vector<string>& res)
    {
        if(lnum > rnum) return;
        if(lnum==0 && rnum==0)
        {
            res.push_back(tmp);
        }
        else
        {
            if(lnum > 0)    generate(lnum-1, rnum, tmp+"(", res);
            if(rnum > 0)    generate(lnum, rnum-1, tmp+")", res);
        }
    }
};
// 非递归：因为每个结果的第一个元素一定是‘(’，所以在重新排列时，第一个元素不参与；
// 罗列所有的可能情况使用 next_permutation() 这个函数；
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)  return {};
        if(n == 1)  return {"()"};        
        vector<string> res;
        string s = "";
        for(int i = 0; i < n; ++i)   s+="()";
    	sort(s.begin(), s.end()); // s = (())
        do{
            if(isLegal(s))  res.push_back(s);
        } while(next_permutation(s.begin()+1,s.end()));
        return res;
    }
    bool isLegal(string& s)
    {
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(') count++;
            else    count--;
            if(count < 0)   return false;
        }
        return true;
    }
};