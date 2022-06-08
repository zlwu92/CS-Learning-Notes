// 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 
// 其中有些元素出现两次而其他元素出现一次。
// 找到所有出现两次的元素。
// 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)    return {};
        // 找nums[i] 和 nums[nums[i] - 1]的关系
        vector<int> res;
        // 正负替换法
        // 找到数字i时，将位置i-1处的数字翻转为负数。
        // 如果位置i-1 上的数字已经为负，则i是出现两次的数字。
        for(int i = 0; i < n; ++i)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0)   res.push_back(idx + 1);
            if(nums[idx] > 0)   nums[idx] = -nums[idx];
        }
        return res;
    }
};