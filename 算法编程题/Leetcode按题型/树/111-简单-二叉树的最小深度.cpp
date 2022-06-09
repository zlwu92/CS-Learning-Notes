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
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        if (!root->left)    return 1 + minDepth(root->right);
        if (!root->right)   return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
// 非递归
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            ++res;
            int i = 0, n = q.size();
            while(i < n)
            {
                TreeNode* tmp = q.front();  q.pop();
                if(!tmp->left && !tmp->right)   return res;
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
                ++i;
            }
        }
        return res;
    }
};