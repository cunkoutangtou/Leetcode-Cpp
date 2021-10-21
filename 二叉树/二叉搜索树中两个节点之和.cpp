给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k 。假设二叉搜索树中节点的值均唯一。

 

示例 1：

输入: root = [8,6,10,5,7,9,11], k = 12
输出: true
解释: 节点 5 和节点 7 之和等于 12
示例 2：

输入: root = [8,6,10,5,7,9,11], k = 22
输出: false
解释: 不存在两个节点值之和为 22 的节点
 

提示：

二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105
 

注意：本题与主站 653 题相同： https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/opLdQZ

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
 //set+中序遍历的迭代形式。
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
        return false;
        set<int> s;
        stack<TreeNode*> sta;
        while(root||!sta.empty()){//只有sta一个条件无法避免左子树为空的情况。
            while(root){
                sta.push(root);
                root=root->left;
            }
            root=sta.top();sta.pop();
            if(s.count(k-root->val))return true;
            s.insert(root->val);
            root=root->right;
        }
        return false;
    }
};
