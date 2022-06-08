// 给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 
// 您可以假设数组的长度最多为10000。
// 例如:
// 输入:
// [1,2,3]
// 输出:
// 2
// 说明：
// 只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）： 
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 首先给数组排序，那么我们最终需要变成的相等的数字就是中间的数
        int res = 0;
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(i < j)    res += nums[j--] - nums[i++];
        return res;
    }
};