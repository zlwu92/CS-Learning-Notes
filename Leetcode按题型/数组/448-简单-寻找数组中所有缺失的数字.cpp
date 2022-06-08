// 给定一个范围在 1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，
// 数组中的元素一些出现了两次，另一些只出现一次。
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 
// 你可以假定返回的数组不算在额外空间内。
// 示例:
// 输入:
// [4,3,2,7,8,2,3,1]
// 输出:
// [5,6]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)    return {};
        vector<int> res;
        // 对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋值为其相反数，
        // 如果已经是负数了，就不变了
        // 不变了，说明这个数重复了，那么他对应位置的数就缺失了！
        for (int i = 0; i < nums.size(); ++i)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)   nums[idx] = -nums[idx];
        }
        // 把留下的整数对应的位置加入结果res中
        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};