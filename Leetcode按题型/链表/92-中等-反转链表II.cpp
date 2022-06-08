// 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
// 说明:
// 1 ≤ m ≤ n ≤ 链表长度。
// 示例:
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = head;
        for(int i = 1; i < m; ++i)  pre = pre->next;
        ListNode *cur = pre->next; // 此时cur在 m 位置
        for(int i = m; i < n; ++i)
        {
            ListNode* tmp = cur->next;
            cur->next = tmp->next; // 断开 tmp 位置，连接2 和 4
            tmp->next = pre->next; // tmp 位置3 接上 2
            pre->next = tmp; // 1接上tmp 位置 3
        }
        return dummy->next;
    }
};