// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。
// 直方图矩形面积要最大的话，需要尽可能的使得连续的矩形多，并且最低一块的高度要高！
// 我们需要按从高板子到低板子的顺序处理，先处理最高的板子，宽度为1，然后再处理旁边矮一些的板子
// 我们需要一个递增栈，当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，就要取出栈顶元素进行处理了，
// 那取出的顺序就是从高板子到矮板子了
// 于是乎遇到的较小的数字只是一个触发，表示现在需要开始计算矩形面积了，
// 为了使得最后一块板子也被处理，这里用了个小 trick，在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了
// 单调栈中不能放高度，而是需要放坐标。
// 由于我们先取出栈中最高的板子，那么就可以先算出长度为1的矩形面积了
// 然后再取下一个板子，此时根据矮板子的高度算长度为2的矩形面积，以此类推，知道数字大于栈顶元素为止，再次进栈
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i)
        {
            if (st.empty() || height[st.top()] < height[i])
            {
                st.push(i);
            }
            else
            {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0)  return 0;
        if(n == 1)  return heights[0];
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            // 先找局部峰值
            if(i+1<n && heights[i] <= heights[i+1]) continue;
            int localPeak = heights[i];
            // 内层循环进行局部内更新
            for(int j = i; j >= 0; --j)
            {
                localPeak = min(localPeak, heights[j]);
                res = max(res, localPeak * (i - j + 1));
            }
        }
        return res;
    }
};
