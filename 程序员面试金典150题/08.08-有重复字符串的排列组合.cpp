class Solution {
public:
    vector<string> permutation(string S) {
    	vector<string> res;
        DFS(S, 0, S.size(), res);
        return res;
    }
    void DFS(string S, int start, int n, vector<string>& res)
    {
        if (start == n && find(res.begin(), res.end(), S) == res.end())
        {
            res.push_back(S);
        }
        for (int i = start; i < n; ++i)
        {
            if(i != start && S[start] == S[i]) continue;  // 去重
            string tmp = S;            
            swap(tmp[start], tmp[i]);
            DFS(tmp, start + 1, n, res);
        }
    }
};