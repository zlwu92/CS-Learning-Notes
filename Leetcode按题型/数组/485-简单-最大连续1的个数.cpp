// 给定一个二进制数组， 计算其中最大连续1的个数。
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int res = 0, cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            // 当前数字为0，那么cnt重置为0，如果不是0，cnt自增1
            cnt = (nums[i] == 0) ? 0 : cnt+1;
            res = max(res, cnt);
        }
        return res;
    }
};