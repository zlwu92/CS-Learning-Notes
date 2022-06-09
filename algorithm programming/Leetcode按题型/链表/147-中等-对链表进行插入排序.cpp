// 链表的 插入排序 实现原理很简单，就是一个元素一个元素的从原链表中取出来，然后按顺序插入到新链表中，
// 时间复杂度为 O(n2)，是一种效率并不是很高的算法，但是空间复杂度为 O(1)，以高时间复杂度换取了低空间复杂度
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while(head)
        {
            // [4,2,1,3]
            ListNode *t = head->next;
            ListNode *cur = dummy;
            // 不论如何，第一次先把头元素加到dummy->next，再跟后面的元素比较交换。
            while (cur->next && cur->next->val <= head->val)
            {
                cur = cur->next;
            }
            head->next = cur->next; // 交换次序
            cur->next = head; // dummy实际连接的节点，尾插法！
            head = t; // 原链表head后移
            // 4 
            // 2 4 
            // 1 2 4 
            // 1 2 3 4 
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode *dummyhead = new ListNode(-1);//伪头指针
        dummyhead->next = head;
        ListNode *prev = head;
        ListNode *node = head->next;
        while (node)
        {
            // [6,5,3,1,8,7,2,4]
            if (prev->val > node->val)
            {
                ListNode* temp = dummyhead;//！！temp要等于dummyhead，这样才可以比较第一个元素
                while (temp->next->val < node->val)//！！！这里是temp->next：因为要修改前面的temp的指向
                {
                    temp = temp->next;//指针后移
                }
                prev->next = node->next;
                node->next = temp->next; // 交换
                temp->next = node; // temp表示的是dummy链接处
                node = prev->next;
            }
            else
            {
                prev = prev->next;
                node = node->next;
            }
            //                  prev node
            // 5 6 3 1 8 7 2 4  | 6   3
            // 3 5 6 1 8 7 2 4  | 6   1
            // 1 3 5 6 8 7 2 4  | 6   8
            // 1 3 5 6 8 7 2 4  | 8   7
            // 1 3 5 6 7 8 2 4  | 8   2
            // 1 2 3 5 6 7 8 4  | 8   4
            // 1 2 3 4 5 6 7 8  | 8   
        }
        return dummyhead->next;
    }
};