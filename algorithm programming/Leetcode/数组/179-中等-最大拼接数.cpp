// 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数
// 示例 1:
// 输入: [10,2]
// 输出: 210
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return "";
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });
        for(auto num : nums)    res += to_string(num);
        return res[0] == '0' ? "0" : res;
    }
};