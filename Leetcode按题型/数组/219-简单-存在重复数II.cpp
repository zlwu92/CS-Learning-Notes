// 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
// 使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; // 记录下标
        for (int i = 0; i < nums.size(); ++i)
        {
            // 前面出现过，m[nums[i]]存好了上一次出现的位置j, 判断i，j的距离差
            if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)   return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};