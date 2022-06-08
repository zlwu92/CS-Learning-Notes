// 输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
int main()
{
    int nums;
    while(cin >> nums)
    {
        ListNode *pHead = new ListNode(-1);
        ListNode *p = pHead;
        for(int i = 0; i < nums; ++i)
        {
            int data;
            cin >> data;
            ListNode *q = new ListNode(data);
            p->next = q;
            p = p->next;
        }
        int Kth;
        cin >> Kth;
        p = pHead;
        if(Kth == 0)    cout << "0" << endl;
        else if(nums-Kth >= 0)
        {
            for(int i = 0; i <= nums-Kth; ++i)
                p = p->next;
            cout << p->val << endl;
        }
        else    cout << "NULL" << endl;
    }
    return 0;
}
// 双指针法亦可，见leetcode第19题