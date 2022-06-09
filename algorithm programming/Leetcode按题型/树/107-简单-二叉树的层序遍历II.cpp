// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            // 由于存储次序改变，改用insert就行
            vector<int> oneLevel;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *tmp = q.front(); q.pop();
                oneLevel.push_back(tmp->val);
                if (tmp->left)  q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};