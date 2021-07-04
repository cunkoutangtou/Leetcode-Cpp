请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：

0 <= 节点个数 <= 1000

链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //迭代，层序遍历。
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
        return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p=nullptr;
        while(!q.empty()){
            p=q.front(); 
            q.pop(); 
            if(p==nullptr)
            continue; 
            TreeNode *temp=p->right;
            p->right=p->left;
            p->left=temp;  
            if(p){
            q.push(p->left);
            q.push(p->right);
            }   
        }
        return root;
    }
};
//递归。
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
        return root;
        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
