// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 非递归
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)    return head;
        // 使用dummy->next表示真正的头结点（head）。这样可以避免判断头指针，统一处理所有的情况
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while(cur->next) // 1->2->3->4->5->NULL
        {
            ListNode* tmp = cur->next; // 为了移动到新表头
            cur->next = cur->next->next;
            tmp->next = dummy->next;
            dummy->next = tmp; // 重新始终由 tmp 指向表头位置
            // 2 1 3 4 5 
            // 3 2 1 4 5 
            // 4 3 2 1 5 
            // 5 4 3 2 1 
        }
        return dummy->next;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL, *cur = head;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = tmp;
        }
        // newHead = 1->null
        // newHead = 2->1->null
        // newHead = 3->2->1->null
        // newHead = 4->3->2->1->null
        // newHead = 5->4->3->2->1->null
        return newHead;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode *newHead = reverseList(head->next); // 直到head指向倒数第二个节点，开始返回出栈
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};