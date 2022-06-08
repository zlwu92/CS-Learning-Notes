// 给定两个二叉树，编写一个函数来检验它们是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if((p && !q) || (!p && q) || (p->val != q->val))    return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// 非递归，利用先序遍历
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty())
        {
            p = s.top();    s.pop();
            q = s.top();    s.pop();
            if(!p && !q)    continue;
            if((p && !q) || (!p && q) || (p->val != q->val))    return false;
            s.push(p->right);   s.push(q->right);   // 先进后出FILO
            s.push(p->left);    s.push(q->left);
        }
        return true;
    }
};