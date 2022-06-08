// 输入：
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// 输出：
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return nullptr;
        // 交换当前左右节点，并直接调用递归即可
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
// 非递归，层序遍历，queue辅助
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front(); q.pop();
            // 交换
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            // 更新迭代节点
            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
        }
        return root;
    }
};
