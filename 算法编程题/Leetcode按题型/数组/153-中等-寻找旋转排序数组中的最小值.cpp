// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
// 请找出其中最小的元素。
// 你可以假设数组中不存在重复元素
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        // 二分搜索
        while (left < right)
        {
            int mid = left + (right-left) / 2;
            // 右半段有序，递增
            if(nums[mid] <= nums[right])    right = mid;
            // 左半段有序，递增
            else    left = mid + 1;
        }
        return nums[right];
    }
};