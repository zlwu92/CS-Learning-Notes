// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 把数组中所有的数字都 '异或' 起来，则每对相同的数字都会得0，
        // 然后最后剩下来的数字就是那个只有1次的数字
        int res = 0; // 0 ^ a = a
        for(auto num : nums)    res ^= num;
        return res;
    }
};