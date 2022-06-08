// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层次遍历如下：
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagDFS(root, 0, res);
        return res;
    }
    void zigzagDFS(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if(!root)   return ;
        if(level >= res.size()) res.push_back({});
        if(level % 2 == 0) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        // 递归
        zigzagDFS(root->left, level+1, res);
        zigzagDFS(root->right, level+1, res);
    }
};
// 非递归
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> oneLevel(n);
            for(int i = 0; i < n; ++i) // for each level
            {
                int idx = leftToRight ? i : (n - 1 - i);
                TreeNode* tmp = q.front();
                oneLevel[idx] = tmp->val;
                q.pop();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
            leftToRight = !leftToRight;
            res.push_back(oneLevel);
        }
        return res;
    }
};