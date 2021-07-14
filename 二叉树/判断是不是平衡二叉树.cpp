输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

 

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

 

限制：

0 <= 树的结点个数 <= 10000

链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //先序遍历，判断每个子树是不是平衡。
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
        return true;
        int re=abs(maxDepth(root->left)-maxDepth(root->right));
        if(re<=1)
        return isBalanced(root->left)&&isBalanced(root->right);
        else
        return false;
    }
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
