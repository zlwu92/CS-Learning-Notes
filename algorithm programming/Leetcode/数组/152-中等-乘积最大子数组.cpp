// 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];
        // 要维护两个变量，当前的最大值，以及最小值，
        // 最小值可能为负数，但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值了
        int p = nums[0];
        int maxP = nums[0];
        int minP = nums[0];
        for(int i = 1; i < n; i++)
        {
            int t = maxP;
            maxP = max(max(maxP * nums[i], nums[i]), minP *nums[i]);
            minP = min(min(t * nums[i], nums[i]), minP * nums[i]);
            p = max(maxP, p);
        }
        return p;
    }
};
