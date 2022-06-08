// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
// 示例：
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 双指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pointers
        if(head == NULL)  return NULL;
        ListNode* prev = head, *curr = head;
        // let curr go ahead n steps
        for(int i = 0; i < n; ++i)  curr = curr->next;
        if(curr == NULL)    return  head->next; // n == list.length()
        while(curr->next)
        {
            // 双指针并排同步向右推移
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = prev->next->next; // jump
        return head;
    }
};
