// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        // 双指针法
        int left = 0, right = height.size() - 1; // 左右墙
        while(left < right)
        {
            int minimum = min(height[left], height[right]);
            if(minimum == height[left])
            {
                left++;
                while(left < right && height[left] < minimum)
                {
                    res += minimum - height[left];
                    left++;
                }
            }
            else
            {
                right--;
                while(left < right && height[right] < minimum)
                {
                    res += minimum - height[right];
                    right--;
                }
            }
        }
        return res;
    }
};
// 用递减stack，遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈
// 注意这里不直接把高度压入栈，而是把坐标压入栈，这样方便在后来算水平距离
// 当遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。
// 此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过！
// 如果多余一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，
// 长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量啦
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n)
        {
            if (st.empty() || height[st.top()] >= height[i])
            {
                st.push(i++);
            }
            else
            {
                int t = st.top();   st.pop();
                if (st.empty()) continue;
                // height[i]--右边界，height[st.top()]--左边界，t--最低值，为坑高度
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};