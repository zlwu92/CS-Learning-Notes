// 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
// 给定的有序链表： [-10, -3, 0, 5, 9],
// 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
// 由于二分查找法每次需要找到中点，而链表的查找中间点可以通过快慢指针来操作
// 找到中点后，要以中点的值建立一个数的根节点，
// 然后需要把原链表断开，分为前后两个链表，都不能包含原中节点，
// 然后再分别对这两个链表递归调用原函数，分别连上左右子节点即可
// 快慢指针法！
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if(!head)   return nullptr;
        return buildTree(head, nullptr);
    }
    TreeNode * buildTree(ListNode* head, ListNode * tail)
    {
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        // 快慢指针找中点
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left  = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};
