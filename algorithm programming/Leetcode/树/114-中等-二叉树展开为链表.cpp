// 例如，给定二叉树
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 典型的DFS策略
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return ;
        TreeNode *cur = root;
        while(cur)
        {
            if(cur->left)
            {
                // 先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，
                // 将左子结点及其后面所有结构一起连到原右子节点的位置，
                // 把原右子节点连到原左子结点最后面的右子节点之后
                TreeNode* tmp = cur->left;
                while(tmp->right)   tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *t = s.top(); s.pop();
            if (t->left)
            {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = nullptr;
            }
            if (t->right) s.push(t->right);
        }
    }
};