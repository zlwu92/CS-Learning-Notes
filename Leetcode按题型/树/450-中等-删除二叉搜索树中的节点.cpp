// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
// 并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
// 一般来说，删除节点可分为两个步骤：
// 首先找到需要删除的节点；
// 如果找到了，删除它。
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return nullptr;
        if(root->val == key)
        {
            if(!root->left || !root->right) root = (root->left) ? root->left : root->right;
            else // 左右节点都存在
            {
                // 需要在右子树找到最小值，即右子树中最左下方的结点，
                // 然后将该最小值赋值给 root，然后再在右子树中调用递归函数来删除这个值最小的结点
                TreeNode *cur = root->right;
                while (cur->left)	cur = cur->left;
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        else if(root->val > key)    root->left = deleteNode(root->left, key);
        else if(root->val < key)    root->right = deleteNode(root->right, key);
        return root;
    }
};