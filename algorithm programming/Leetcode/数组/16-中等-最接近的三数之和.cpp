// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
// 使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int length = n - 2;
        for(int i = 0; i < length; ++i)
        {
            // no need to remove duplicates
            int left = i+1, right = n-1;
            if (nums[i]*3 > target)   return min(res, nums[i] + nums[i+1] + nums[i+2]);
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right]; 
                if (abs(sum - target) < abs(res - target))	res = sum;
                int diff = target - sum;      
                if (diff == 0)    return target;
                if (diff > 0) left++;
                else    right--;
            }
        }
        return res;
    }
};

