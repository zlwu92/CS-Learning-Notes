// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须原地修改，只允许使用额外常数空间。
// 1　　2　　7　　4　　3　　1
// 1　　(2)　　7　　4　　(3)　　1
// 1　　(3)　　7　　4　　(2)　　1
// 1　　(3　　1　　2　　4　　7)
// 双指针法
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2, j = n-1;
        while(i >= 0 && nums[i] >= nums[i+1])   --i;
        if(i >= 0)
        {
            while(nums[j] <= nums[i])   --j;
            // swap when nums[j] > nums[i]
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};