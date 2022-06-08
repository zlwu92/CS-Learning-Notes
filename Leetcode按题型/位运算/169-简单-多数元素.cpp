// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素
// 从0到31位，每次统计下数组中该位上0和1的个数，
// 如果1多，那么将结果 res 中该位变为1，最后累加出来的 res 就是过半数了
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < 32; ++i)
        {
            int ones = 0, zeros = 0;
            for(int num : nums)
            {
                if(ones > n/2 || zeros > n/2)   break;
                if((num & (1 << i)) != 0)   ones++;
                else    zeros++;
            }
            if(ones > zeros)    res |= (1 << i);
        }
        return res;
    }
};