// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
// 示例 1:
// 输入: 1->2->3->4->5->NULL, k = 2
// 输出: 4->5->1->2->3->NULL
// 解释:
// 向右旋转 1 步: 5->1->2->3->4->NULL
// 向右旋转 2 步: 4->5->1->2->3->NULL
// 先遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，成为一个循环链表
// 在往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return nullptr;
        ListNode* cur = head;
        // 第一轮先计算链表长度
        int n = 1;
        while(cur->next)
        {
            cur = cur->next;
            ++n;
        }
        cur->next = head; // 首尾相接形成环
        int m = n - k % n;
        for(int i = 0; i < m; ++i)  cur = cur->next;
        ListNode* newHead = cur->next;
        cur->next = nullptr; // 断开k处连接边即完成
        return newHead;
    }
};