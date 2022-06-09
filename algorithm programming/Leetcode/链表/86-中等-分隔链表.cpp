// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 你应当保留两个分区中每个节点的初始相对位置。
// 示例:
// 输入: head = 1->4->3->2->5->2, x = 3
// 输出: 1->2->2->4->3->5
// 就是将所有小于给定值的节点取出组成一个新的链表，
// 此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后即可
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *tmp = newDummy;
        while(cur->next)
        {
            if (cur->next->val < x)
            {
                tmp->next = cur->next;
                cur->next = cur->next->next; // 将<x的节点从原链表中剔除掉
                tmp = tmp->next;
                tmp->next = nullptr;    
            }
            else    cur = cur->next;
        }
        tmp->next = dummy->next; // 此时原链表只剩下>=x的节点
        return newDummy->next;
    }
};