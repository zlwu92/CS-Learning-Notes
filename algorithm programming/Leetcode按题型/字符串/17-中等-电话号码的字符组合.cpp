// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 递归法
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        int n = digits.size();
        unordered_map<char, string> dmap = { {'2',"abc"},
                                            {'3',"def"},
                                            {'4',"ghi"},
                                            {'5',"jkl"},
                                            {'6',"mno"},
                                            {'7',"qprs"},
                                            {'8',"tuv"},
                                            {'9',"wxyz"} };
        string str = dmap[digits[0]];
        int m = str.size(); // first size
        if(n == 1)
        {
            string tmp = "";
            for(int i = 0; i < m; ++i)
            {
                res.push_back(tmp+str[i]);
            }
            return res;
        }
        else
        {
            vector<string> rest = letterCombinations(digits.substr(1, n-1));
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < rest.size(); ++j)
                {
                    res.push_back(str[i]+rest[j]);    
                }
            }
            return res;
        }
    }
};
// 非递归
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        int n = digits.size();
        unordered_map<char, string> dmap = { {'2',"abc"},
                                            {'3',"def"},
                                            {'4',"ghi"},
                                            {'5',"jkl"},
                                            {'6',"mno"},
                                            {'7',"qprs"},
                                            {'8',"tuv"},
                                            {'9',"wxyz"} };
        for(int i = 0; i < n; ++i)
        {
            string str = dmap[digits[i]];
            vector<string> tmp;
            for (int j = 0; j < str.size(); ++j) 
            {
                for (string s : res)    tmp.push_back(s + str[j]);
            }
            res = tmp;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tmp;
            string str = dict[digits[i] - '0'];
            for (int j = 0; j < str.size(); ++j) {
                for (string s : res) tmp.push_back(s + str[j]);
            }
            res = tmp;
        }
        return res;
    }
};