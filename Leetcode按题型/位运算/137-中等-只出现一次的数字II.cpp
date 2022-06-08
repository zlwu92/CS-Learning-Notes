// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                sum += (nums[j]>>i) & 1; // 提取每个数对应位之和
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};