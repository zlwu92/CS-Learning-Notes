// 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // BST最重要的性质是就是左<根<右, 用中序
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* tmp = root;
        int count = 0;
        while(!s.empty() || tmp)
        {
            while(tmp)
            {
                s.push(tmp);
                tmp = tmp->left;
            }
            tmp = s.top();  s.pop();
            ++count;
            if(count == k) return tmp->val;
            // 看是否还有右子节点，没有继续弹栈回溯，有就入栈处理之！
            tmp = tmp->right;
        }
        return 0;
    }
};
// 分治
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 由于 BST 的性质，可以快速定位出第k小的元素是在左子树还是右子树
        int count = countNode(root->left);
        if(k <= count)  return kthSmallest(root->left, k);
        else if(k > count + 1)  return kthSmallest(root->right, k - count - 1);
        else    return root->val;
    }
    int countNode(TreeNode* root)
    {
        if(!root)   return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
};
// Follow up，进一步优化以适应频繁的 查找 和 修改
// 应该修改原树结点的结构，使其保存包括当前结点和其左右子树所有结点的个数，
// 这样就可以快速得到任何左子树结点总数来快速定位目标值了
// 在求第k小元素的函数中，先生成新的树，然后调用递归函数
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }
    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }
    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        } else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};