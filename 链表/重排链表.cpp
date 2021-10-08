给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1:



输入: head = [1,2,3,4]
输出: [1,4,2,3]
示例 2:



输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]
 

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
 

注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/ 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/LGjMqU

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //快慢指针找到链表后半部分，反转后半部分，再一个一个将两个链表编在一起即可。
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* p=rever(slow->next);
        slow->next=nullptr;
        ListNode *nh=new ListNode(),*q=nh;
        while(p&&head){
            q->next=head;
            head=head->next;
            q=q->next;
            q->next=p;
            p=p->next;
            q=q->next;
        }
        q->next=p?p:head;
        head=nh->next;
    }
    ListNode *rever(ListNode *h){
        if(!h||!h->next)
        return h;
        ListNode* nh=rever(h->next);
        h->next->next=h;
        h->next=nullptr;
        return nh;
    }
};
