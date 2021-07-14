给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数

链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //二叉搜索树->中序遍历。
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if(root==nullptr)
        return 0;
        return kth(root,k);
    }
    int kth(TreeNode* root, int &k) {//注意在这个函数中只要三个re赋值是互斥的，从左子树得到结果了就不需要管本层与右子树了。
        int re=0;
        if(root->right)
        re=kth(root->right,k);
        if(!re&&--k==0){
            re=root->val;
        }
        if(!re&&root->left)
        re=kth(root->left,k);
        return re;
    }
};
