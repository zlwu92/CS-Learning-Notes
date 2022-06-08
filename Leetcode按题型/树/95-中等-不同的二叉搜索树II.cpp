// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树
// 建树问题一般来说都是用 分治递归 来解
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return {};
        return generateDFS(1, n);
    }
    vector<TreeNode*> generateDFS(int start, int end)
    {
        if (start > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i) // 将其中的每个数字都当作根结点
        {
            auto left = generateDFS(start, i-1);
            auto right = generateDFS(i+1, end);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};