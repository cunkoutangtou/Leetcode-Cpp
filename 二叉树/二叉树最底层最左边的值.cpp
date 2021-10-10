给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:



输入: root = [2,1,3]
输出: 1
示例 2:



输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

提示:

二叉树的节点个数的范围是 [1,104]
-231 <= Node.val <= 231 - 1 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/LwUNpT

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //每当访问到的层数+1时，记录该数即可，由于先序遍历的特性，它一定是该层最左边的数。
class Solution {
    int H=0;
    int re=0;
public:
    int findBottomLeftValue(TreeNode* root) {
        fi(root,1);
        return re;
    }
    void fi(TreeNode *root,int h){
        if(!root->left&&!root->right&&h>H){
            H=h;
            re=root->val;
        }
        if(root->left)
        fi(root->left,h+1);
        if(root->right)
        fi(root->right,h+1);
    }
};
