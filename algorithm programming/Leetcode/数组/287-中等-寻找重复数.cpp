// 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
// 可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
// 示例 1:
// 输入: [1,3,4,2,2]
// 输出: 2
// 说明：
// 不能更改原数组（假设数组是只读的）。
// 只能使用额外的 O(1) 的空间。
// 时间复杂度小于 O(n^2) 。
// 数组中只有一个重复的数字，但它可能不止重复出现一次。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)  return 1;
        // 快慢指针，利用数组数值和下标的特殊关系
        int slow = 0, fast = 0;
        // 最后必然会陷入无限循环！，相遇于环的起始位置
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)    break;
        }
        int newHead = 0;
        // 第二次迭代，从环起点 相遇于 重复点！
        while(1)
        {
            slow = nums[slow];
            newHead = nums[newHead]; // 数组链表起点开始
            if(slow == newHead)   break;
        }
        return slow;
    }
};