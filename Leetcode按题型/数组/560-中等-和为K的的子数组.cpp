// 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 && k == 0)    return 1;
        if(n == 1 && k == 1)    return 1;
        int res = 0, sum = 0;
        // 空数组的前缀和为0，所以前缀和为0的连续子数组个数初始化为1
        unordered_map<int, int> m{{0, 1}};
        // key为从0到当前位置的和sum，value为从0开始和为sum的位置个数
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            res += m[sum - k]; // 当前和为sum,之前和为sum-k的个数
            ++m[sum];
        }
        return res;
    }
};