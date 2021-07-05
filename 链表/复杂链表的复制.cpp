请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

 

示例 1：



输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：



输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：



输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。

链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//使用哈希表先存储链表每个节点的复制，然后连接起来
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return head;
        Node *p=head;
        map<Node*,Node*> m;
        while(p){
            m[p]=new Node(p->val);
            p=p->next;
        }    
        p=head; 
        while(p){
            m[p]->next=m[p->next];
            m[p]->random=m[p->random];
            p=p->next;
        }
        return m[head];
    }
};
//在每个结点后面复制本节点，然后连接节点，最后拆开成两个链表。
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return head;
        Node *p=head,*q=nullptr;
        while(p){//复制
            q=new Node(p->val);
            q->next=p->next;
            p->next=q;
            p=q->next;
        }    
        p=head; 
        while(p){//链接
            if(p->random)
            p->next->random=p->random->next;
            p=p->next->next;
        }
        p=head;
        q=p->next;
        head=q;
        while(q->next){//拆分
            p->next=q->next;
            q->next=p->next->next;
            p=p->next;
            q=q->next;
        }
        p->next=nullptr;
        return head;
    }
};
