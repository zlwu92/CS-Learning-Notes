// 一遍hash map
// 使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。
// 注意，map中不存在相同元素，所以返回值只能是1或0。
// 使用find，返回的是被查找元素的位置，没有则返回map.end()
// map底层实现为红黑数，undered_map底层实现为哈希表，两者均不能有重复的建，均支持[]运算符
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]
// 假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // {contents, index}
        for(int i = 0; i < nums.size(); ++i)
        {
            if(map.count(target - nums[i]))
            {
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};