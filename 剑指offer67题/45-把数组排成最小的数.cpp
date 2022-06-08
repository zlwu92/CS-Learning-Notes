// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 示例 1:
// 输入: [10,2]
// 输出: "102"
// 示例 2:
// 输入: [3,30,34,5,9]
// 输出: "3033459"
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        string res;
        if(n == 0)  return {};
        sort(nums.begin(), nums.end(), cmp);
        for(auto num : nums)    res += to_string(num);
        return res;
    }
    static bool cmp(int a, int b)
    {
        string m = to_string(a);
        string n = to_string(b);
        string mn = m + n;
        string nm = n + m;
        return mn < nm;
    }
};