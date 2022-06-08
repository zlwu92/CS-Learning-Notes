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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildDFS(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildDFS( vector<int> &preorder, int pLeft, int pRight, 
                        vector<int> &inorder, int iLeft, int iRight )
    {
        // 先序的顺序的第一个肯定是根
        // 关键的条件就是树中没有相同元素
        // 在中序遍历中也定位出根节点的位置
        // 并以根节点的位置将中序遍历拆分为左右两个部分
        if (pLeft > pRight || iLeft > iRight) return nullptr;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i)
        {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode* curRoot = new TreeNode(preorder[pLeft]); // inorder[i]
        curRoot->left = buildDFS(preorder, pLeft+1, pLeft + i-iLeft, inorder, iLeft, i-1);
        curRoot->right = buildDFS(preorder, pLeft + i-iLeft + 1, pRight, inorder, i+1, iRight);
        return curRoot;
    }
};
// 非递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size())   return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        // 初始时栈中存放了根节点（前序遍历的第一个节点），指针指向中序遍历的第一个节点；
        for (int i = 1; i < preorder.size(); ++i)
        {
            int preorderVal = preorder[i]; // 从第一个子节点开始枚举前序遍历
            TreeNode* node = stk.top();
            // 左子树
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else // 右子树
            {
                // 先回退找上一级的root，赋给node
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop(); // 栈中的顺序，从left向root走
                    ++inorderIndex; // 中序顺序，也是从left向root走 
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
