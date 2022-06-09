// 给定两个数组，编写一个函数来计算它们的交集。
// 说明：
// 输出结果中的每个元素一定是唯一的。
// 我们可以不考虑输出结果的顺序。
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 将一个数组排序，然后遍历另一个数组
        unordered_map<int, int> m;
        for(auto num : nums1)  m[num] = 0;
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        for(auto num : nums1)
        {
            // 考虑去重
            if(m[num] == 0 && binarySearch(nums2, num))
            {
                res.push_back(num);
                m[num] = 1; // visited
            }
        }
        return res;
    }
    bool binarySearch(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) left = mid + 1;
            else    right = mid - 1;
        }
        return false;
    }
};