// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
// 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target)   return nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            if(target <= nums[i])   return i;
        }
        return -1;
    }
};
// 二分搜索法 O(logn)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target)   return nums.size();
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};