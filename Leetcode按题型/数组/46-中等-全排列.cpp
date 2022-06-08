// 给定一个 没有重复 数字的序列，返回其所有可能的全排列
// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
// 回溯递归
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res)
    {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i)
        {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
            // cout << start << ", " << i << ": ";
            // for(auto r : res[res.size()-1])   cout << r << " ";
            // cout << endl;
        }
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        recursion(nums, 0, nums.size()-1, res);
        return res;
    }
    void recursion(vector<int> nums, int left, int right, vector<vector<int>>& res)
    {    
        if(left == right) res.push_back(nums);
        else
        {
            for(int i = left; i <= right; ++i)
            {
                swap(nums[left], nums[i]);
                recursion(nums, left+1, right, res);
            }
        }
    }
};
// 非递归
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.push_back(nums);
        while(1) // next_permutation
        {
            int i = n-2, j = n-1;
            while(i >= 0 && nums[i] >= nums[i+1])   --i;
            if(i >= 0)
            {
                while(nums[j] <= nums[i])   --j;
                // swap when nums[j] > nums[i]
                swap(nums[j], nums[i]);
            }
            reverse(nums.begin()+i+1, nums.end());
            if(!isEqual(res[0], nums, n))	res.push_back(nums);
            else    break;
        }
        return res;
    }
    bool isEqual(vector<int>& a, vector<int>& b, int len)
    {
        for(int i = 0; i < len; ++i)
        {
            if(a[i] != b[i])    return false;
        }
        return true;
    }
};
// 库函数法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end()))
        {
            res.push_back(num);
        }
        return res;
    }
};