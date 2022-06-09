// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
// 假设一个二叉搜索树具有如下特征：
// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 非递归，使用栈
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty())
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(pre && p->val <= pre->val)   return false;
            pre = p;
            p = p->right;
        }
        return true;
    }
};
// 中序递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* node, TreeNode*& pre)
    {
        if (!node) return true;
        bool res = inorder(node->left, pre);
        if(!res)    return false;
        if (pre) {
            if (node->val <= pre->val) return false;
    //        cout << node->val << " " << pre->val << endl;
        }        
        pre = node; // node > pre，中序
        return inorder(node->right, pre);
    }
};
class Solution {
bool isBSTUtil(struct TreeNode* root, long long& prev) 
{ 
    if (root)
    { 
        if (!isBSTUtil(root->left, prev))	return false;  
        // 当前结点小于等于它的直接前驱顶点，返回false 
        if (root->val <= prev)	return false;  
        //初始化pre 为当前结点
        prev = root->val;   
        return isBSTUtil(root->right, prev); 
    }  
    return true; 
} 
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LONG_MIN; 
        return isBSTUtil(root, prev); 
    }
};
