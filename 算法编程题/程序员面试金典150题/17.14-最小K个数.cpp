// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> q; // 最大堆保存
        for (int a : arr) 
        {
			q.push(a);
			if (q.size() > k)   q.pop(); // 删除堆顶最大元素
		}
        while (!q.empty())
        {
			res.push_back(q.top());
			q.pop();
		}
		return res;
    }
};