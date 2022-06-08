// 表头存最高位，翻转了链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if(head == NULL)  return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        while(curr->next != NULL)
        {
            // 类似于截断链表再逆向循环补齐
            ListNode* tmp = curr->next;
            curr->next = curr->next->next; // 1. 断开，跳过当前节点，便于下一轮循环
            tmp->next = dummy->next; // 2. 把本应接到右边下一节点的指针接到左边的上一节点，实现当前部分的翻转
            dummy->next = tmp;
        }
        return dummy->next;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)    return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        while(l1 != NULL || l2 != NULL)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            val2 += (val1 + carry);
            carry = val2 / 10;
            int res = val2 % 10;
            curr->next = new ListNode(res);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        // check whether new node is needed at the end
        if(carry == 1)  curr->next = new ListNode(1);
        return reverseList(dummy->next);
    }
};