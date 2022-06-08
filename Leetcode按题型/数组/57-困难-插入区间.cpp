// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
// 示例 1:
// 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出: [[1,5],[6,9]]
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), m = newInterval.size();
        if(m == 0)  return intervals;
        vector<vector<int>> res;
        int cur = 0; // 记录新区间该插入的位置
        for (int i = 0; i < n; ++i)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]); // 放在前面的小区间
                ++cur;
            }
            else if (intervals[i][0] > newInterval[1])
            {
                res.push_back(intervals[i]); // 放在后面的大区间
            }
            else
            {
                // 更新区间，方便最后退出循环插入中间
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};