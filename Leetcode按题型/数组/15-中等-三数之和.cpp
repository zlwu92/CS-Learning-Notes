// 一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
// 请你找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
// 双指针遍历
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(nums.empty() || n < 3)   return {};
        sort(nums.begin(), nums.end()); // nlogn
        for(int i = 0; i < n-2; ++i)
        {           
            if(nums[i] > 0) break;            
        //    if(nums[i]+nums[i+1]+nums[i+2]>0)   break; // 
            if(i>0 && nums[i] == nums[i-1])    continue;   // 
        //    if(nums[i]+nums[n-2]+nums[n-1]<0)   continue; // 
            int target = 0 - nums[i];
            int left = i + 1, right = n - 1;
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left<right && nums[left] == nums[left+1]) left++;
                    while (left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum  < target)  left++;
                else    right--;
            }
        }
        return res;    
    }
};