// 给定一个二叉树，返回它的 前序 遍历。
//  示例:
// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 
// 输出: [1,2,3]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// root -> left -> right
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp)
        {
            if(tmp != nullptr)
            {
                s.push(tmp);
                res.push_back(tmp->val);
                tmp = tmp->left;
            }
            else
            {
                tmp = s.top(); // 退回来
                s.pop();
                tmp = tmp->right;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root); // step 1
        while(!s.empty())
        {
            TreeNode* tmp = s.top(); // step 2
            s.pop();    // step 3
            res.push_back(tmp->val); // step 4
            if(tmp->right)  s.push(tmp->right);
            if(tmp->left)   s.push(tmp->left);
        }
        return res;
    }
};
