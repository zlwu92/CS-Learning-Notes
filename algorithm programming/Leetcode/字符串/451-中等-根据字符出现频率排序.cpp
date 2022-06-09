// 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto ch : s)    m[ch]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            return m[a] > m[b] || (m[a] == m[b] && a < b);
        });
        return s;
    }
};
// 优先队列性能高！
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> m;
        for (char c : s)    ++m[c];
        for (auto a : m)    q.push({a.second, a.first});
        while (!q.empty())
        {
            auto t = q.top(); q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
};