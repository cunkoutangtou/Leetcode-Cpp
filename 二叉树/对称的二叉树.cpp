请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
 

限制：

0 <= 节点个数 <= 1000

链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //通过不同的方向先序遍历同一颗树，对每层节点进行比较。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        return true;
        return doulePreorder(root,root);
    }
    bool doulePreorder(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2)
        return true;
        if(!root1||!root2||root1->val!=root2->val)
        return false;
        return doulePreorder(root1->left,root2->right)&&doulePreorder(root1->right,root2->left);
    }
};
