输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

 

示例:
给定如下二叉树，以及目标和 target = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
 

提示：

节点总数 <= 10000

链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof

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
//深度优先，先序遍历，回溯
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root)
        return {};
        vector<vector<int>> re;
        vector<int> temp;
        bt(root,target,re,temp);
        return re;
    }
    void bt(TreeNode* root, int target, vector<vector<int>> &re,vector<int> &temp){
        bool isleaf=!root->left&&!root->right;
        target-=root->val;
        temp.push_back(root->val);
        if(target==0&&isleaf){
            re.push_back(temp);
        }
        if(root->left)
        bt(root->left,target,re,temp);
        if(root->right)
        bt(root->right,target,re,temp);
        temp.pop_back();
        target+=root->val;
    }
};
