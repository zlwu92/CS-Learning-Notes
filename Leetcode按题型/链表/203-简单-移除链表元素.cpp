// 删除链表中等于给定值 val 的所有节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)   return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// 非递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)   return nullptr;
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while(pre->next)
        {
            if(pre->next->val == val)
            {
                ListNode* tmp = pre->next; // 为了删除
                pre->next = pre->next->next;
                tmp = nullptr;  delete tmp;
            }
            else    pre = pre->next;
        }
        return dummy->next;
    }
};