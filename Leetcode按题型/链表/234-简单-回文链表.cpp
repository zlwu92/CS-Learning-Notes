// 请判断一个链表是否为回文链表。
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// 在找到中点后，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        // 用快慢指针来找中点
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 此时slow在中点位置，然后翻转
        ListNode* mid = slow->next;
        while(mid->next)
        {
            ListNode* tmp = mid->next;
            mid->next = mid->next->next; // tmp->next
            tmp->next = slow->next;
            slow->next = tmp;
        }
        // 两段挨个比较
        ListNode* pre = head;
        while(slow->next)
        {
            slow = slow->next;
            if(slow->val != pre->val)   return false;
            pre = pre->next;
        }
        return true;
    }
};