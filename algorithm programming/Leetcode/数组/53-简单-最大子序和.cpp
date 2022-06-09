// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 贪心法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for(auto num : nums)
        {
            // 判断curSum是否 < 0，从而判断是否要重新计数
            curSum = max(num, curSum + num);
            res = max(res, curSum);
        }
        return res;
    }
};
// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
		dp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; ++i)
        {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);	
			if (res < dp[i])	res = dp[i];
		}
		return res;
    }
};
// 分治法 O(nlogn)
// 把数组一分为二，分别找出左边和右边的最大子数组之和，
// 然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return divider(nums, 0, nums.size() - 1);
    }
    int divider(vector<int>& nums, int left, int right)
    {
        if (left >= right)  return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = divider(nums, left, mid - 1);
        int rmax = divider(nums, mid + 1, right);
        int mmax = nums[mid];
        
        int t = mmax;
        for(int i = mid-1; i >= left; --i)
        {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for(int i = mid+1; i <= right; ++i)
        {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};