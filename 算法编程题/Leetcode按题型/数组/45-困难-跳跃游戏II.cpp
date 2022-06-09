// 给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
// 示例:
// 输入: [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置
class Solution {
public:
    int jump(vector<int>& nums) {
        // 贪心
        int end = 0;
        int maxPosition = 0; 
        int steps = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            // 每次找局部最优的，这次没找到，下次找到会松弛，以便获得全局最优解
            maxPosition = max(maxPosition, i + nums[i]);
            if(i == end) // 遇到边界，就更新边界，并且步数加一
            {
                end = maxPosition;
                steps++;
            }
            cout << i << " " << maxPosition << " " << end << endl;
            if(end == nums.size()-1)    break;
        }
        return steps;
    }
};