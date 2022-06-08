// 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
// 例如，从根到叶子节点路径 1->2->3 代表数字 123。
// 计算从根到叶子节点生成的所有数字之和。
// 说明: 叶子节点是指没有子节点的节点。
// 示例 1:
// 输入: [1,2,3]
//     1
//    / \
//   2   3
// 输出: 25
// 解释:
// 从根到叶子节点路径 1->2 代表数字 12.
// 从根到叶子节点路径 1->3 代表数字 13.
// 因此，数字总和 = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        return sumDFS(root, 0);
    }
    int sumDFS(TreeNode* root, int sum)
    {
        if(!root)   return 0;
        sum = sum * 10 + root->val;
        if(!root->left && !root->right) return sum;
        return sumDFS(root->left, sum) + sumDFS(root->right, sum);
    }
};
// 非递归
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            if(!tmp->left && !tmp->right)   res += tmp->val;
            if(tmp->left)
            {
                tmp->left->val += tmp->val * 10;
                s.push(tmp->left);
            }
            if(tmp->right)
            {
                tmp->right->val += tmp->val * 10;
                s.push(tmp->right);
            }
        }
        return res;
    }
};