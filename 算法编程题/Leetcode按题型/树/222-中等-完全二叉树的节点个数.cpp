// 给出一个完全二叉树，求出该树的节点个数。
// 说明：
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点
// 递归
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
    int countNodes(TreeNode* root) {
    	return root ? (1 + countNodes(root->left) + countNodes(root->right)) : 0;
    }
};
// 非递归
class Solution {
public:
    int countNodes(TreeNode* root) {
        // 思路: 由 root 根结点往下，分别找最靠左边和最靠右边的路径长度
        // 如果长度相等，则证明二叉树最后一层节点是满的，是满二叉树，直接返回节点个数
        // 如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while(pLeft)
        {
            hLeft++;
            pLeft = pLeft->left;
        }
        while(pRight)
        {
            hRight++;
            pRight = pRight->right;
        }
        if(hLeft == hRight) return pow(2, hLeft) - 1; // 满二叉树
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};