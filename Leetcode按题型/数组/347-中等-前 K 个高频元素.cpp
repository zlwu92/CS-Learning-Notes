// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 用 HashMap 来做，建立数字和其出现次数的映射
        // 用一个最大堆来按照映射次数从大到小排列
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m)   q.push({it.second, it.first});
        for(int i = 0; i < k; ++i)
        {
            res.push_back(q.top().second); // 这里的second实际上是map中的first
            q.pop();
        }
        return res;
    }
};