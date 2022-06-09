// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 把数组中所有的数分配一个状态，true 表示这个数在子集中出现，false 表示在子集中不出现，
// 那么对于一个长度为n的数组，每个数字都有出现与不出现两种情况
// 每个子集的序号的二进制表示，把是1的位对应原数组中的数字取出来就是一个子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        // 位运算法
        int total = 1 << nums.size();
        for(int i = 0; i < total; ++i)
        {
            vector<int> out = getSubSet(nums, i);
            res.push_back(out);
        }
        return res;
    }
    vector<int> getSubSet(vector<int> &nums, int i)
    {
        vector<int> subset;
        int idx = 0;
        for (int j = i; j > 0; j >>= 1)
        {
            // 相当于每次提取i的二进制位中的1的index，然后对应到数组位置上取数
            if ((j & 1) == 1)
            {
                subset.push_back(nums[idx]);
            }
            ++idx;
        }
        return subset;
    }
};
// 递归
// 原集合每一个数字只有两种状态，要么存在，要么不存在，
// 那么在构造子集时就有选择和不选择两种情况，所以可以构造一棵二叉树，
// 左子树表示选择该层处理的节点，右子树表示不选择，最终的叶节点就是所有子集合
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())    return {};
        vector<vector<int> > res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, out, res);
        return res;
    }
    void DFS(vector<int>& nums, int pos, vector<int>& out, vector<vector<int>>& res)
    {
        res.push_back(out); // 空集也是一个解
        for(int i = pos; i < nums.size(); ++i)
        {
            out.push_back(nums[i]);
            DFS(nums, i+1, out, res);
            out.pop_back();
        }
    }
};
