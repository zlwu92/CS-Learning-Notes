// 在整数数组 nums 中，是否存在两个下标 i 和 j，
// 使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，
// 且满足 i 和 j 的差的绝对值也小于等于 ķ 。
// 如果存在则返回 true，不存在返回 false。
// 示例 1:
// 输入: nums = [1,2,3,1], k = 3, t = 0
// 输出: true
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(n == 0)    return false;
        map<long, int> m; // 记录数字和其下标之间的映射
        int i = 0, j = 0;
        while(i < n)
        {
            // 保证窗口内|i - j| <= k
            if(i - j > k)
            {
                m.erase(nums[j]);
                ++j;
            }
            // 找| nums[i] - nums[j] | <= t
            auto tmp = m.lower_bound((long)nums[i] - t);
            if(tmp != m.end() && abs(tmp->first - nums[i]) <= t)    return true;
            m[nums[i]] = i;
            ++i;
        }
        return false;
    }
};