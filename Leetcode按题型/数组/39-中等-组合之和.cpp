// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。
// 说明：
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。
// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
// 递归
// start 记录当前的递归到的下标，out 为一个解，res 保存所有已经得到的解，
// 每次调用新的递归函数时，此时的 target 要减去当前数组的的数
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
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
            out.push_back(candidates[i]);
            DFS(candidates, target-candidates[i], i, out, res); // candidates 中的数字可以无限制重复被选取。
            out.pop_back(); // 回溯
        }
    }
};