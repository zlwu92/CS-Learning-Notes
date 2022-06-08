// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
// 就是当两个链表各只有一个结点的时候，一定是有序的。
// 而归并排序的核心其实是分治法 Divide and Conquer，
// 就是将链表从中间断开，分成两部分，左右两边再分别调用排序的递归函数 sortList()，
// 得到各自有序的链表后，再进行 merge()，这样整体就是有序的了
// 将链表从中间断开的方法，采用的就是快慢指针，
// 因为快指针每次走两步，慢指针每次走一步，当快指针到达链表末尾时，慢指针正好走到中间位置
class Solution {
public:
	ListNode* sortList(ListNode* head) {
        // 归并排序 比较合适
        if(!head || !head->next)    return head;
        ListNode *slow = head, fast = head, pre = head;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 中间断开，进行分治
        return mergeTwoLists(sortList(head), sortList(slow));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1 && l2)
        {
        	if(l1->val < l2->val)
        	{
        		curr->next = l1;
        		l1 = l1->next;
        	}
        	else
        	{
        		curr->next = l2;
        		l2 = l2->next;
        	}
        	curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

// 快速排序
void QuickSortList(Node* Head, Node* Tail)
{
    if(Head == nullptr || Head->_next == nullptr || Head == Tail)   return;

    Node* cur = Head->_next;
    Node* pre = Head;
    int key = Head->_data;//以头节点作为基准值

    while(cur != tail)
    {
        if(cur->_data < key){
            pre = pre->_next;
            if(pre != cur){
                std::swap(pre->_data,cur->_data);
            }
        }
        cur = cur->_next;
    }

    std::swap(Head->_data, pre->_data);//将基准值放到枢纽位置
    QuickSortList(Head,pre);
    QuickSortList(pre->_next,tail);
}