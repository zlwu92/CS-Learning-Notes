// 输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。
// 输入描述:
// 1 输入链表结点个数
// 2 输入头结点的值
// 3 按照格式插入各个结点
// 4 输入要删除的结点的值
// 输出描述:
// 输出删除结点后的序列，每个数后都要加空格
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
void insertNode(ListNode* head, int input, int indexVal)
{
    ListNode* curptr = head, *curnext;
    while ( curptr != nullptr && curptr->val != indexVal) // 去重处理
    {
        curptr = curptr->next;   //指针指向下一个结点
    }// 经过while后，指针定位到要找的位置处
    ListNode* temptr = new ListNode(input); //新建一个结点
    curnext = curptr->next;    
    curptr->next = temptr;
    temptr->next = curnext;     // 三步完成结点的插入
}
void disVal( ListNode* head )
{
    ListNode* curptr = head;
    while ( curptr != nullptr )
    {
        cout << curptr->val << " ";  // 最后一个数字后边也有空格，不然过不了
        curptr = curptr->next;   //指针指向下一个结点
    }
    cout << endl;
}
void delNode( ListNode* head, int input)
{
    ListNode* curptr = head, *precur;
    if (curptr->val == input)  // 头结点单独处理
    {
        head = head->next;
        delete curptr;
    }
    curptr = head->next;
    precur = head;
    // 双指针法
    while (curptr != nullptr && curptr->val != input)
    {      
        curptr = curptr->next;   //指针指向下一个结点
        precur = precur->next;
    }
    precur->next = curptr->next;  // jump
    delete curptr;
}
int main()
{
    int num, headVal, delVal;
    int input, preVal;
    while ( cin >> num )
    {
        cin >> headVal;
        ListNode* head = new ListNode(headVal);
        for ( int i = 0; i < num - 1; ++i)
        {
            cin >> input >> preVal;
            insertNode( head, input, preVal );
        }
        cin >> delVal;
        delNode( head, delVal );
        disVal( head );
    }
    return 0;
}