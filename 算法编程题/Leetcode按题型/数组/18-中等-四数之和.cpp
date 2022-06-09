// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
// 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums.empty() || n < 4)   return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; ++i)
        {
            if(target<=0 && nums[i]>0) break;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue; // key optimize!
            for (int j = i + 1; j < n - 2; ++j) 
            {
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(j>i+1 && nums[j] == nums[j-1])   continue;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue; // key optimize!
                int left = j+1, right = n-1;
                while(left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left+1]) left++;
                        while(left<right && nums[right] == nums[right-1]) --right;
                        ++left; 
                        --right;
                    }
                    else if(sum < target)   left++;
                    else right--;
                }
            }
        }
        return res;
    }
};
