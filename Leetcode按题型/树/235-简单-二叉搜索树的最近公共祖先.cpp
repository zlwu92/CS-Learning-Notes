// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
// 最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 分治递归，由于是BST，如果root>max(p,q)，则p q都在左子树
        // 如果root<min(p,q)，则p q都在右子树，如果p<root<q，则一边一个
        if(!root)   return nullptr;
        if(root->val > max(p->val, q->val)) return lowestCommonAncestor(root->left, p, q);
        if(root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
        else    return root;
    }
};
// 非递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(1)
        {
            if(root->val > max(p->val, q->val)) root = root->left;
            else if(root->val < min(p->val, q->val))    root = root->right;
            else    break;
        }
        return root;
    }
};