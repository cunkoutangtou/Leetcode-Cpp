请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

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
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000

链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//两个栈交替存储。注意两个节点交换后其子节点也交换位置，那么这两个节点和其子节点成镜像。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<vector<int>> re;
        vector<int> temp;
        stack<TreeNode*> sta[2];
        int current=0,next=1;
        TreeNode *p;
        sta[current].push(root);
        while(!sta[0].empty()||!sta[1].empty()){
            p=sta[current].top();
            sta[current].pop();
            temp.push_back(p->val);
            if(next){
                if(p->left){
                    sta[next].push(p->left);
                }
                if(p->right){
                    sta[next].push(p->right);
                }
            }
            else{
                if(p->right){
                    sta[next].push(p->right);
                }
                if(p->left){
                    sta[next].push(p->left);
                }
            }
            if(sta[current].empty()){//切换层数
                current=next;
                next=1-next;
                re.push_back(temp);
                temp.clear();
            }
        }
        return re;
    }
};
