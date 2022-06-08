// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
// 示例：
// 二叉树：[3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：
// [
//   [3],
//   [9,20],
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
// BFS
// BFS使用队列，把每个还没有搜索到的点依次放入队列，然后再弹出队列的头部元素当做当前遍历点。BFS总共有两个模板：
// 如果不需要确定当前遍历到了哪一层，BFS模板如下。
// while queue 不空：
//     cur = queue.pop()
//     for 节点 in cur的所有相邻节点：
//         if 该节点有效且未访问过：
//             queue.push(该节点)
// 如果要确定当前遍历到了哪一层，BFS模板如下。
// 这里增加了level表示当前遍历到二叉树中的哪一层了，也可以理解为在一个图中，现在已经走了多少步了。
// size表示在当前遍历层有多少个元素，也就是队列中的元素数，我们把这些元素一次性遍历完，即把当前层的所有元素都向外走了一步。
// level = 0
// while queue 不空：
//     size = queue.size()
//     while (size --) {
//         cur = queue.pop()
//         for 节点 in cur的所有相邻节点：
//             if 该节点有效且未被访问过：
//                 queue.push(该节点)
//     }
//     level ++;
// 时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)
// 空间复杂度：队列中元素的个数不超过 nn 个，故渐进空间复杂度为 O(n)
// 非递归 BFS 用 queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({root});
        while(!q.empty())
        {
            vector<int> kLevel;
            int n = q.size();
            // q中只保留每一层的节点
            for(int i = 0; i < n; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                kLevel.push_back(tmp->val);
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
            res.push_back(kLevel);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({root});
        while(!q.empty())
        {
        //    vector<int> kLevel;
            int n = q.size();
            res.push_back(vector <int> ()); // each level
            for(int i = 0; i < n; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
        //        kLevel.push_back(tmp->val);
                res.back().push_back(tmp->val);
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
        //    res.push_back(kLevel);
        }
        return res;
    }
};
// 递归 DFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if (node->left) levelorder(node->left, level + 1, res);
        if (node->right) levelorder(node->right, level + 1, res);
    }
};

