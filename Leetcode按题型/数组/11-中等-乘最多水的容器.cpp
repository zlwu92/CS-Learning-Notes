// n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 且 n 的值至少为 2。
// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49
// O(n) 双指针解法！
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = 0;
        while(i < j)
        {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
        //    (height[i] < height[j]) ? i++ : j--;            
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
};
