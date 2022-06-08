// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 时间复杂度分析：K 条链表的总结点数是 N，平均每条链表有 N/K 个节点，
// 因此合并两条链表的时间复杂度是 O(N/K)。
// 从 K 条链表开始两两合并成 1 条链表，因此每条链表都会被合并 logK 次，
// 因此 K 条链表会被合并 K * logK 次，
// 因此总共的时间复杂度是 K*logK * N/K 即 O（NlogK）
// 分治法 简单来说就是不停的对半划分，比如k个链表先划分为合并两个 k/2 个链表的任务 O(NlogK)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)  return nullptr;
        if(n == 1)  return lists[0];
    //    int mid = (n+1) / 2;
        while(n > 1)
        {
            int mid = (n+1) / 2;
            for(int i = 0; i < n/2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i+mid]);
            }
            n = mid;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// 最小堆法 priority queue O(NlogK)
class Solution {
public:
    //运算符重载< 小顶堆
    struct cmp1 {
        int val;
        ListNode* pa;
        bool operator < (const ListNode* pb) const {
            return val > pb->val;
        }
    };
    //重写仿函数
    struct cmp2 {
        bool operator () (ListNode* pa, ListNode* pb) {
            return pa->val > pb->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<Type, Container, Functional>
        // 当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型
        priority_queue<ListNode*, vector<ListNode*>, cmp2 > q;
        for(auto node : lists) 
        {
            if(node)    q.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!q.empty())
        {
            auto tmp = q.top();
            q.pop();
            curr->next = tmp;
            curr = curr->next;
            if(curr->next)  q.push(curr->next);
        }
        return dummy->next;
    }
};
