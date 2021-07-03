定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof

//下面两种方式一样，只是获取头结点的方式不同。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode **newhead=new ListNode*();
        rever(head,newhead);
        return *newhead;
    }
    void rever(ListNode *head,ListNode **newhead){
        if(head->next==nullptr){
            *newhead=head;
            return;
        }
        rever(head->next,newhead);
        head->next->next=head;
        head->next=nullptr;
        return;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
