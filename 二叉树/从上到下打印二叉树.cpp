从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]
 

提示：

节点总数 <= 1000

链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//层序遍历
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<int> re;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p;
        while(!q.empty()){
            p=q.front();
            q.pop();
            re.push_back(p->val);
            if(p->left)
            q.push(p->left);
            if(p->right)
            q.push(p->right);
        }
        return re;
    }
};
