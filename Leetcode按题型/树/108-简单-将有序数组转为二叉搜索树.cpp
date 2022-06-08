// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        TreeNode* curRoot = new TreeNode(nums[mid]);
        // 准备递归
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        curRoot->left = sortedArrayToBST(left);
        curRoot->right = sortedArrayToBST(right);
        return curRoot;
    }
};