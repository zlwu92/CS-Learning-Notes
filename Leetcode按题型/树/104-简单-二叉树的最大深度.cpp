// 给定一个二叉树，找出其最大深度。
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。
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
    int maxDepth(TreeNode* root) {
        // 递归的完美应用
        if(!root)   return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// 非递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        int res = 0;
        // 层序迭代
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            ++res;
            int n = q.size(), i = 0;
            while(i < n) // each level
            {
                TreeNode* tmp = q.front();  q.pop();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
                ++i;
            }
        }
        return res;
    }
};
