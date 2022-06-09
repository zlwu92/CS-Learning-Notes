// 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数
// 思路是把1放在数组第一个位置 nums[0]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 总的思路：最小应该是 1 最大应该是 nums.size()
        // 将元素按照元素的值返回它应该在得地方
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)   return i + 1;
        }
        return n + 1;
    }
};