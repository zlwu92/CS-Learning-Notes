// 基本思想是：要想获得n个不同字符的所有排列
// 可以先求得n个不同字符中任意n−1个字符的所有排列
// 然后将第n个字符插入到n−1个字符的每一个排列的第0个位置，
// 从而得到n个不同字符的所有排列
class Solution {
public:
    vector<string> permutation(string S) {
        int n = S.size();
        vector<string> res;
        if (n == 0)
        {
            res.push_back("");
            return res;
        }
        string tmp = S;
        for (int i = 0; i < n; ++i)
        {
            vector<string> partials = permutation(S.erase(i,1));
            for (string s : partials)
            {
                res.push_back(tmp[i] + s);
            }
            S = tmp;
        }
        return res;
    }
};
class Solution {
public:
    vector<string> permutation(string S) {
    	vector<string> res;
        DFS(S, 0, S.size(), res);
        return res;
    }
    void DFS(string S, int start, int n, vector<string>& res)
    {
        if (start == n)	res.push_back(S);
        for (int i = start; i < n; ++i)
        {
            string tmp = S;
            swap(tmp[start], tmp[i]);
            DFS(tmp, start + 1, n, res);
        }
    }
};