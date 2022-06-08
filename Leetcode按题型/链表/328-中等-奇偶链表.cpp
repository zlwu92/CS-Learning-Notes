// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
// 请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
// 请尝试使用 原地算法 完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
// 说明：
// 应当保持奇数节点和偶数节点的相对顺序。
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        // 利用奇偶指针
        ListNode *odd = head, *even = head->next;
        ListNode *even_head = head->next;
        while(even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head; // 两段首尾相接
        return head;
    }
};