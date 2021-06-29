输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]

限制：

0 <= 链表长度 <= 10000

https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/


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
    vector<int> reversePrint(ListNode* head) {
        if(head==nullptr)
        return {};
        vector<int> re;
        priback(head,re);
        return re;
    }
    void priback(ListNode *head,vector<int> &re){
        if(head->next==nullptr){
            re.push_back(head->val);
            return;
        }
        priback(head->next,re);
        re.push_back(head->val);
    }
};
