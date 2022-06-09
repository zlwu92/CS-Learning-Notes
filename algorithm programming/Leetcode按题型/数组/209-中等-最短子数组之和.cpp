// 给定一个含有 n 个正整数的数组和一个正整数 s，找出该数组中满足其和 ≥ s 的长度最小的子数组，并返回其长度。
// 如果不存在符合条件的子数组，返回 0。
// 示例：
// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法
// 需要定义两个指针 left 和 right，分别记录子数组的左右的边界位置
// 然后让 right 向右移，直到子数组和大于等于给定值或者 right 达到数组末尾，，此时更新最短距离
// 并且将 left 像右移一位，然后再 sum 中减去移去的值，
// 然后重复上面的步骤，直到 right 到达末尾，且 left 到达临界位置，即要么到达边界，要么再往右移动，和就会小于给定值。
// 滑动窗口双指针法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0;
        int sum = 0, n = nums.size(), res = n + 1;
        while(right < n)
        {
            while(sum < s && right < n)   sum += nums[right++];
            while(sum >= s)
            {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == n + 1 ? 0 : res;
    }
};