// 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
// 现有一个链表 -- head = [4,5,1,9]，它可以表示为:
// 说明:
// 链表至少包含两个节点。
// 链表中所有节点的值都是唯一的。
// 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
// 不要从你的函数中返回任何结果。
// 先把当前节点的值用下一个节点的值覆盖了，然后我们删除下一个节点即可
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 下一个节点的值赋给node，因为不可能从上一个节点直接跳到下一个节点
        ListNode *tmp = node->next;
        node->next = tmp->next; //虽然是删除当前节点，但赋值了以后就变成跳过删除下一个节点了
        delete tmp;
    }
};