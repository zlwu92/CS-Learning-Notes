// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
// 请找出其中最小的元素。
// 注意数组中可能存在重复的元素。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])     right = mid;
            else if(nums[mid] > nums[right])    left = mid + 1;
            else --right; // 遇到重复元素时，jump
        }
        return nums[right];
    }
};