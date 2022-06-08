// 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动将会使 n - 1 个元素增加 1。 
// 示例:
// 输入:
// [1,2,3]
// 输出:
// 3
// 解释:
// 只需要3次移动（注意每次移动会增加两个元素的值）：
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 给 n-1 个数字加1，效果等同于给那个未被选中的数字减1，并不影响数字间相对差异
        // 那么问题也可能转化为，将所有数字都减小到最小值！
        int mm = INT_MAX, res = 0;
        for(int num : nums) mm = min(mm, num);
        for(int num : nums) res += num - mm;
        return res;
    }
};