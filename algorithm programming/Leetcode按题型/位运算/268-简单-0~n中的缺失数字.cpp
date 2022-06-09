// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        // 将这个少了一个数的数组合0到n之间完整的数组异或一下，
        // 那么相同的数字都变为0了，剩下的就是少了的那个数字了
        for (int i = 0; i < nums.size(); ++i)
        {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};