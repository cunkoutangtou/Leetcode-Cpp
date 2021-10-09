给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

示例1：

输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
解释:
          1
         / \
        3   2
       / \   \  
      5   3   9 
示例2：

输入: root = [1,2,3]
输出: [1,3]
解释:
          1
         / \
        2   3
示例3：

输入: root = [1]
输出: [1]
示例4：

输入: root = [1,null,2]
输出: [1,2]
解释:      
           1 
            \
             2     
示例5：

输入: root = []
输出: []
 

提示：

二叉树的节点个数的范围是 [0,104]
-231 <= Node.val <= 231 - 1
 

注意：本题与主站 515 题相同： https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hPov7L

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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> re;
        while(!q.empty()){
            int ma=INT_MIN;
            int si=q.size();
            for(int i=0;i<si;i++){//每次要把每层的节点全部遍历完。
                TreeNode *node=q.front();
                q.pop();
                ma=max(node->val,ma);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            re.push_back(ma);
        }
        return re;
    }
};
