// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
// 找出给定目标值在数组中的开始位置和结束位置。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]
// 必然要用二分搜索！
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        // 先算第一个位置
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (right == nums.size() || nums[right] != target)  return res;
        res[0] = right;
        right = nums.size();
        // 再算最后一个位置
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] <= target)	left = mid + 1;
            else	right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};
// 简洁版
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIdx = firstGreaterEqual(nums, target);
        if (startIdx == nums.size() || nums[startIdx] != target)  return {-1, -1};
        return {startIdx, firstGreaterEqual(nums, target + 1) - 1};
    }
    int firstGreaterEqual(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] < target)	left = mid + 1;
            else    right = mid;
        }
        return right;
    }
};