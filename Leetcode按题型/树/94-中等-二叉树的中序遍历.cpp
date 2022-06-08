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
// left -> root -> right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)    return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp)
        {
            if(tmp != nullptr)
            {
                s.push(tmp);
                tmp = tmp->left;
            }
            else
            {
                tmp = s.top();
                s.pop();
                res.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)    return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp)
        {
            while(tmp != nullptr)
            {
                s.push(tmp);
                tmp = tmp->left;                
            }
            tmp = s.top(); // 退回来
            s.pop();
            res.push_back(tmp->val);
            tmp = tmp->right;
        }
        return res;
    }
};