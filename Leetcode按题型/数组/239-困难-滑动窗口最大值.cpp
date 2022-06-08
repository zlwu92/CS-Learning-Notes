// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回滑动窗口中的最大值。
// 进阶：
// 你能在线性时间复杂度内解决此题吗？
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 0)  return {};
        vector<int> res;
        deque<int> window;
        int right = 0;
        while(right < nums.size())
        {
            // 后续，窗口每右移一次，都会产生一个最大值[队列头位置的元素]
            if(!window.empty() && window.front() <= right - k){   //队头不在窗口范围内
                window.pop_front();
            }
            while(!window.empty() && nums[right] > nums[window.back()]){   //待入队元素比队尾元素大
                window.pop_back();
            }
            window.push_back(right);
            right++;
            // 变量的最前端（也就是 window.front()）是此次遍历的最大值的下标
            if(right >= k) res.push_back(nums[window.front()]);
        }
        return res;
    }
};