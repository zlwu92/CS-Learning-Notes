// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
// 递归
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0 || k <= 0 || k > n)   return res;
        vector<int> out;
        DFS(n, k, 1, out);
        return res;
    }
    void DFS(int n, int k, int start, vector<int> &out)
    {
        if (out.size() == k)
        {
            res.push_back(out);
            return;
        }
        // 优化：剪枝
        for (int i = start; i <= n - (k - out.size()) + 1; ++i)
        {
            out.push_back(i);
            DFS(n, k, i + 1, out);
            out.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // 利用组合公式 C(n, k) = C(n-1, k-1) + C(n-1, k)
        if(k>n || k<0)  return {};
        if(k == 0)  return {{}};
        // 接下来分两部分 处理
        vector<vector<int>> res = combine(n-1, k-1);
        for(auto &a : res)   a.push_back(n);
        for(auto &a : combine(n-1, k))   res.push_back(a);
        return res;
    }
};

