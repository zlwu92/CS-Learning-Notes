// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意:
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200
// 示例 1:
// 输入: [1, 5, 11, 5]
// 输出: true
// 解释: 数组可以分割成 [1, 5, 5] 和 [11].
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 它的每一个元素只能是0或1，每个元素仅用1 bit空间
        bitset<10001> bits(1);
        // 把 bits 向左平移 num 位，然后再或上原来的 bits，这样所有的可能出现的和位置上都为1
        for (int num : nums)	bits |= bits << num;
    	// [1,5,11,5]	true
    	// 1 1 0 0 0 1 1 0 0 0 1 | 1 1 0 0 0 1 1 0 0 0 1 
        // 遍历完整个数组后，去看 bits[sum >> 1] 是否为1即可
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};