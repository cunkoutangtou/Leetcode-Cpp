给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

示例1：


输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：

输入：l1 = [0], l2 = [0]
输出：[0]
 

提示：

链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
 

进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lMSNwu

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
 //先反转链表，再逐个相加存到新的链表中。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        return l2;
        if(l2==nullptr)
        return l1;
        l1=rever(l1);
        l2=rever(l2);
        int carry=0;
        ListNode *nh=new ListNode(),*q;
        while(l1&&l2){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            q=new ListNode(sum%10);
            q->next=nh->next;
            nh->next=q;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                int sum=l1->val+carry;
                carry=sum/10;
                q=new ListNode(sum%10);//头插法，新的链表正好逆序。
                q->next=nh->next;
                nh->next=q;
                l1=l1->next;
            }
        }
        else if(l2){
            while(l2){
                int sum=l2->val+carry;
                carry=sum/10;
                q=new ListNode(sum%10);
                q->next=nh->next;
                nh->next=q;
                l2=l2->next;
            }
        }
        if(carry){
            q=new ListNode(1);
            q->next=nh->next;
            nh->next=q;
        }
        return nh->next;
    }
    ListNode* rever(ListNode* h){
        if(h==nullptr||h->next==nullptr){
            return h;
        }
        ListNode *nh=rever(h->next);
        h->next->next=h;
        h->next=nullptr;
        return nh;
    }
};
//使用栈，省去反转链表的过程。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        return l2;
        if(l2==nullptr)
        return l1;
        stack<ListNode*> s1,s2;
        while(l1){
            s1.push(l1);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2);
            l2=l2->next;
        }
        int carry=0;
        ListNode *nh=new ListNode(),*q;
        while(!s1.empty()&&!s2.empty()){
            int sum=s1.top()->val+s2.top()->val+carry;
            carry=sum/10;
            q=new ListNode(sum%10);
            q->next=nh->next;
            nh->next=q;
            s1.pop();
            s2.pop();
        }
        if(s1.size()){
            while(!s1.empty()){
                int sum=s1.top()->val+carry;
                carry=sum/10;
                q=new ListNode(sum%10);
                q->next=nh->next;
                nh->next=q;
                s1.pop();
            }
        }
        else if(s2.size()){
            while(!s2.empty()){
                int sum=s2.top()->val+carry;
                carry=sum/10;
                q=new ListNode(sum%10);
                q->next=nh->next;
                nh->next=q;
                s2.pop();
            }
        }
        if(carry){
            q=new ListNode(1);
            q->next=nh->next;
            nh->next=q;
        }
        return nh->next;
    }
};
