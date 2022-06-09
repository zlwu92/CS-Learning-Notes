// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 递归
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())    return {};
        vector<vector<int> > res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, out, res);
        return res;
    }
    void DFS(vector<int>& nums, int pos, vector<int>& out, vector<vector<int>>& res)
    {
        res.push_back(out); // 空集也是一个解
        for(int i = pos; i < nums.size(); ++i)
        {
            out.push_back(nums[i]);
            DFS(nums, i+1, out, res);
            out.pop_back();
            // 对同一个pos位置，要加去重操作
            while(i + 1 < nums.size() && nums[i+1] == nums[i])  ++i;
        }
    }
};
