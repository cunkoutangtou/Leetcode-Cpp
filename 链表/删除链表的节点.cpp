给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

说明：

题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof

//由于不需要delete节点，单指针就够用了。如果题目给的不是被删节点的值而是它的地址，若不是尾结点则可通过其将其后的值复制到它这，然后删除后面的节点来保证O（1）的复杂度。
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr)
        return head;
        ListNode *p=head;
        if(head->val==val){
            return head->next;
        }
        while(p->next){
            if(p->next->val==val){
                p->next=p->next->next;
                return head;
            }
            p=p->next;
        }
        return head;
    }
};
