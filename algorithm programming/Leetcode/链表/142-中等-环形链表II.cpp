// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
// 如果 pos 是 -1，则在该链表中没有环。
// 说明：不允许修改给定的链表。
// 你是否可以不用额外空间解决此题？
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
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next)   return nullptr;
        // 此时只能说明fast 和 slow 都位于环中的某一个节点，并不一定是起始位置
        // 再相遇的位置一定是链表中环的起始位置！
        // 因为第一次相遇时fast恰好比slow 多走了一圈
        // 设 x = head 到环的起点的距离，y = 环的起点到他们相遇的点的距离，z = 环长度
        // 则 x + y + z = (x+y)*2，故 x + y = z;
        // 重新开始，head 运行到环起点 和 相遇点到环起点 的距离也是相等的
        // 相当于他们同时减掉了 环的起点到他们相遇的点的距离！
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

/*
扩展问题
在网上搜集了一下这个问题相关的一些问题，思路开阔了不少，总结如下：

1. 环的长度是多少？

2. 如何找到环中第一个节点（即Linked List Cycle II）？

3. 如何将有环的链表变成单链表（解除环）？

4. 如何判断两个单链表是否有交点？如何找到第一个相交的节点？

首先我们看下面这张图：



设：链表头是X，环的第一个节点是Y，slow和fast第一次的交点是Z。
各段的长度分别是a,b,c，如图所示。环的长度是L。
slow和fast的速度分别是qs,qf。

下面我们来挨个问题分析。

1. 方法一（网上都是这个答案）：

第一次相遇后，让slow,fast继续走，记录到下次相遇时循环了几次。
因为当fast第二次到达Z点时，fast走了一圈，slow走了半圈，
而当fast第三次到达Z点时，fast走了两圈，slow走了一圈，正好还在Z点相遇。

方法二：

第一次相遇后，让fast停着不走了，slow继续走，记录到下次相遇时循环了几次。

方法三（最简单）：

第一次相遇时slow走过的距离：a+b，fast走过的距离：a+b+c+b。

因为fast的速度是slow的两倍，所以fast走的距离是slow的两倍，有 2(a+b) = a+b+c+b，可以得到a=c（这个结论很重要！）。

我们发现L=b+c=a+b，也就是说，从一开始到二者第一次相遇，循环的次数就等于环的长度。

2. 我们已经得到了结论a=c，那么让两个指针分别从X和Z开始走，每次走一步，那么正好会在Y相遇！也就是环的第一个节点。

3. 在上一个问题的最后，将c段中Y点之前的那个节点与Y的链接切断即可。

4. 如何判断两个单链表是否有交点？
先判断两个链表是否有环，如果一个有环一个没环，肯定不相交；
如果两个都没有环，判断两个列表的尾部是否相等；
如果两个都有环，判断一个链表上的Z点是否在另一个链表上。

如何找到第一个相交的节点？
求出两个链表的长度L1,L2（如果有环，则将Y点当做尾节点来算），
假设L1<L2，用两个指针分别从两个链表的头部开始走，长度为L2的链表先走(L2-L1)步，然后两个一起走，直到二者相遇。
*/
