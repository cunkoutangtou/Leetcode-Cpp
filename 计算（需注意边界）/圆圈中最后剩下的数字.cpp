0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

 

示例 1：

输入: n = 5, m = 3
输出: 3
示例 2：

输入: n = 10, m = 17
输出: 2
 

限制：

1 <= n <= 10^5
1 <= m <= 10^6

链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof

//环形链表模仿圆，效率贼低。
class Solution {
    struct LinkList{
        int data;
        LinkList *next;
    };
public:
    int lastRemaining(int n, int m) {
        LinkList *p,*head,*q;
        head=new LinkList{0,nullptr};
        q=head;
        for(int i=1;i<n;i++){
            p=new LinkList{i,nullptr};
            q->next=p;
            q=q->next;
        }
        p->next=head;
        p=p->next;
        while(p->next!=p){
            int cnt=1;
            while(cnt<m){
                p=p->next;
                q=q->next;
                cnt++;
            }
            q->next=p->next;
            //delete p;
            p=q->next;
        }
        return p->data;
    }
};
//数学公式推导，推导递推公式，f(n,m)和f(n-1,m)的关系。
class Solution {
public:
    int lastRemaining(int n, int m) {
        int re=0,last=0;
        for(int i=2;i<=n;i++){
            last=(last+m)%i;
        }
        return last;
    }
};
