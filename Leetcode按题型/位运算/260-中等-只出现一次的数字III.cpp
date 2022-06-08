// 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
// 注意：
// 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
// 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
// 分析：不妨假设出现一个的两个元素是x，y，那么最终所有的元素异或的结果就是res = x^y。
// 并且res！=0，那么我们可以找出res二进制表示中的某一位是1。
// 对于原来的数组，我们可以根据这个位置是不是1就可以将数组分成两个部分
// x，y在不同的两个子数组中。
// 而且对于其他成对出现的元素，要么在x所在的那个数组，要么在y所在的那个数组
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 用于记录，区分两个数组
        int diff = 0, n = nums.size();
        for(auto num : nums)  diff ^= num;
        diff &= (-diff);    // 取diff最后一位1
        vector<int> res(2, 0);
        for(auto num : nums)
        {
        	// 分属两个不同的数组
            if((num & diff) == 0)   res[0] ^= num;
            else    res[1] ^= num;
        }
        return res;
    }
};