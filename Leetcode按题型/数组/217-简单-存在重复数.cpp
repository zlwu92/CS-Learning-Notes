// 给定一个整数数组，判断是否存在重复元素。
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])	return true;
        }
        return false;
    }
};