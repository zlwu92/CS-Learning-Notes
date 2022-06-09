// 给定一个无序的整数数组，找到其中最长上升子序列的长度。
// 示例:
// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4 
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)    return n;
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            int left = 0, right = res.size();
            // 遍历原数组，每个用一次二分搜索找res中第一个>=nums[i]的数字
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(res[mid] < nums[i])  left = mid + 1;
                else    right = mid;
            }
            // 如果这个数字不存在，那么直接在 res 数组后面加上遍历到的数字
            if(right >= res.size()) res.push_back(nums[i]);
            // 如果存在，则将这个数字 更新替换 为当前遍历到的数字
            else    res[right] = nums[i];
            // 10 
            // 9 
            // 2 
            // 2 5 
            // 2 3 
            // 2 3 7 
            // 2 3 7 101 
            // 2 3 7 18 
        }
        return res.size();
    }
};