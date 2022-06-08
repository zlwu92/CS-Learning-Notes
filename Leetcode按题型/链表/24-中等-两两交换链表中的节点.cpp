// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// 示例:
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while(prev->next && prev->next->next)
        {
            ListNode* tmp = prev->next->next;  // tmp->val = 2
            prev->next->next = tmp->next;  // prev->next->val = 1, 1->next->val = 3
            tmp->next = prev->next;     // 2->next->val = 1
            prev->next = tmp;       // prev->next->val = 2 = curr_head
            prev = tmp->next;   // prev->val = 1 = next_head
        }
        return dummy->next;
    }
};
// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* res = head->next; // res->val = 2    
        head->next = swapPairs(head->next->next);
        res->next = head; // swap 
        return res;
    }
};