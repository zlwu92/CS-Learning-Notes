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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildDFS(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildDFS( vector<int> &inorder, int iLeft, int iRight, 
                        vector<int> &postorder, int pLeft, int pRight)
    {
        if (iLeft > iRight || pLeft > pRight) return nullptr;
        // 先找root
        int i = 0;
        for (i = iLeft; i < inorder.size(); ++i)
        {
            if (inorder[i] == postorder[pRight]) break;
        }
        TreeNode *curRoot = new TreeNode(postorder[pRight]); // inorder[i]
        // i - iLeft 是计算inorder中根节点位置和左边起始点的距离
        curRoot->left = buildDFS(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i-iLeft - 1);
        curRoot->right = buildDFS(inorder, i + 1, iRight, postorder, pLeft + i-iLeft, pRight-1);
        return curRoot;
    }
};