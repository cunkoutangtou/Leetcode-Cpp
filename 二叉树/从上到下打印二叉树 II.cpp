从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 

提示：

节点总数 <= 1000

链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//记录下下一层要打印的节点个数与当前层还需要打印的节点个数，本层打印完则切换到下一层。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<vector<int>> re;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        int tobeprinted=1,nextlevel=0;
        TreeNode *p;
        while(!q.empty()){
            p=q.front();
            q.pop();
            temp.push_back(p->val);
            if(p->left){
            q.push(p->left);
            nextlevel++;
            }
            if(p->right){
            q.push(p->right);
            nextlevel++;
            }
            if(--tobeprinted==0){//切换层数
                tobeprinted=nextlevel;
                nextlevel=0;
                re.push_back(temp);
                temp.clear();
            }
        }
        return re;
    }
};
