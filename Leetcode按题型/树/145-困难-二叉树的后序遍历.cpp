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
// left -> right -> root
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> res;
        TreeNode* tmp = root;
        stack<TreeNode*> s;
        while(!s.empty() || tmp)
        {
            if(tmp != nullptr)
            {
                // 先压栈，为了保留根节点，后前插，为了调整前面根节点的输出顺序
                // 根 右 左 -> 左 右 根，通过insert实现 
                s.push(tmp);
                res.insert(res.begin(), tmp->val);
                tmp = tmp->right;
            }
            else
            {
                tmp = s.top(); // 开始回溯
                s.pop();
                tmp = tmp->left;
            }
        }
        return res;
    }
};