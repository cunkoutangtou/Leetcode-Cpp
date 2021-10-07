输入两个链表，找出它们的第一个公共节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //利用栈，现将两个列表分别压入两个栈，然后不断弹出直到栈顶元素不同。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
        return nullptr;
        stack<ListNode*> s1,s2;
        while(headA){
            s1.push(headA);
            headA=headA->next;
        }
        while(headB){
            s2.push(headB);
            headB=headB->next;
        }
        ListNode *p=nullptr;
        while(!s1.empty()&&!s2.empty()&&s1.top()==s2.top()){
            p=s1.top();
            s1.pop();
            s2.pop();
        }
        return p;
    }
};
//先遍历两个链表，得到长度，让指针长的列表先走它们长度的差值，再一起走直到遇到相同的。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
        return nullptr;
        ListNode *p=headA,*q=headB;
        int cnt1=0,cnt2=0;
        while(p){
            cnt1++;
            p=p->next;
        }
        while(q){
            cnt2++;
            q=q->next;
        }
        int diff=0;
        if(cnt1>cnt2){
            p=headA;
            q=headB;
            diff=cnt1-cnt2;
        }
        else{
            p=headB;
            q=headA;
            diff=cnt2-cnt1;
        }
        while(diff){
            p=p->next;
            diff--;
        }
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};
//两个链表同时走，一个走完自己的就走另一个的，这样就能弥补两个链表长度不同的差别。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *a=headA, *b=headB;
        while(a!=nullptr||b!=nullptr){
            if(a==b)
            return a;
            a=(a==nullptr)?headB:a->next;
            b=(b==nullptr)?headA:b->next;
        }
        return nullptr;
    }
};
