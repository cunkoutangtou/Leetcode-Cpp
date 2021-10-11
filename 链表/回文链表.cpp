给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

 

示例 1：



输入: head = [1,2,3,3,2,1]
输出: true
示例 2：



输入: head = [1,2]
输出: false
 

提示：

链表 L 的长度范围为 [1, 105]
0 <= node.val <= 9
 

进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

 

注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/aMhZSa

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
 //用一个指针记录前面的节点，递归到尾部，然后和头部比较。
class Solution {
    ListNode *fp;
public:
    bool isPalindrome(ListNode* head) {
        fp=head;
        return recurse(head);
    }
    bool recurse(ListNode* head){
        if(head==nullptr)
        return true;
        if(recurse(head->next)==false)//将后面的结果转发给前面递归的函数。
        return false;
        if(fp->val==head->val){
            fp=fp->next;
            return true;
        }
        return false;
    }
};
