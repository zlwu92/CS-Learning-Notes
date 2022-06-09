// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用一次。
// 说明：
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0, out, res);
        return res;
    }
    void DFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res)
    {
        if(target < 0) return;
        if(target == 0)
        {
            res.push_back(out);
            return ;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1])  continue; // 去重
            out.push_back(candidates[i]);
            DFS(candidates, target-candidates[i], i+1, out, res); // candidates 中的每个数字不能重复使用
            out.pop_back(); // 回溯
        }
    }
};