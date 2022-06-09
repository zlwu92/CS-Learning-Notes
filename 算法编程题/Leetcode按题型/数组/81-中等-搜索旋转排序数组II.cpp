// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
// 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            if (nums[mid] < nums[right])
            {
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else    right = mid - 1;
            }
            else if(nums[mid] > nums[right])
            {
                if(nums[left] <= target && target < nums[mid])  right = mid - 1;
                else    left = mid + 1;
            }
            else    --right; // 去重
        }
        return false;
    }
};