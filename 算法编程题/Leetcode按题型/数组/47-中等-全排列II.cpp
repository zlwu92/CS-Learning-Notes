// 给定一个可包含重复数字的序列，返回所有不重复的全排列
// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
// 简单回溯
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        recursion(nums, 0, nums.size()-1, res);
        return res;
    }
    void recursion(vector<int> nums, int left, int right, vector<vector<int>>& res)
    {    
        if(left == right) res.push_back(nums);
        else
        {
            for(int i = left; i <= right; ++i)
            {
                //去重操作
                if(i != left && nums[left] == nums[i]) continue;
                swap(nums[left], nums[i]);
                recursion(nums, left+1, right, res);
            }
        }
    }
};
// 库函数法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end()))
        {
            res.push_back(num);
        }
        return res;
    }
};