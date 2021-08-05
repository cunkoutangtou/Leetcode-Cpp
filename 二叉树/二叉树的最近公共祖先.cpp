给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

链接：https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //后序遍历递归判断子树中是否同时包含p和q，第一个同时包含的即为最近公共祖先。
class Solution {
    TreeNode *re;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        judge(root,p,q);
        return re; 
    }
    bool judge(TreeNode *root,TreeNode* p, TreeNode* q){
        if(root==nullptr)
        return false;
        //后序遍历，从低向上找到的第一个公共祖先肯定是最近的，判断左右子树中是否有p和q
        bool ltree=judge(root->left,p,q);
        bool rtree=judge(root->right,p,q);
        //p和q其中一个为另一个的祖先或者两者都不是对方的祖先。
        if(((root==p||root==q)&&(ltree||rtree))||(ltree&&rtree)){
            re=root;
            return false;
        }
        //当前节点为p或者q则可以直接返回true，否则返回其左右子树的情况
        if(root==p||root==q)
        return true;
        else
        return ltree||rtree;
    }
};
//深度遍历找出根到p，q的两条路径，比较两条路径找到最后一个共同祖先节点。
class Solution {
    int f;//标志位，判断是否找到路径。
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> lp,lq;
        f=0;
        dfs(root,p,lp);
        f=0;
        dfs(root,q,lq);
        int diff=lp.size()-lq.size();
        list<TreeNode*>::iterator it1=lp.begin(),it2=lq.begin(),re=it1;
        while(*it1==*it2){//继续找共同祖先节点
            re=it1;
            it1++;
            it2++;
        }
        return *re; 
    }
    void dfs(TreeNode *root,TreeNode *r,list<TreeNode*> &li){
        if(root==nullptr)
        return;
        if(root==r){
            li.push_back(root);
            f=1;
            return;
        }
        li.push_back(root);
        dfs(root->left,r,li);
        if(f)//找到就不用向右遍历了
        return;
        dfs(root->right,r,li);
        if(f)//找到就不用弹出存储的路径节点了
        return;
        li.pop_back();
    }
};
//利用哈希表为目标节点路径记录其父节点，然后从目标节点处遍历两条路径找第一个公共节点。
class Solution {
    unordered_map<TreeNode*,TreeNode*> fa[2];
    unordered_map<TreeNode*,bool> visited;
    int f;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f=0;
        dfs(root,p,fa[0]);
        f=0;
        dfs(root,q,fa[1]);
        fa[0][root]=nullptr;
        fa[1][root]=nullptr;
        visited[p]=true;
        while(p){
            visited[fa[0][p]]=true;
            p=fa[0][p];
        }
        while(q){
            if(visited[q])
            return q;
            q=fa[1][q];
        }
        return nullptr;
    }
    void dfs(TreeNode *root,TreeNode *r,unordered_map<TreeNode*,TreeNode*> &m){
        if(root==r){
            f=1;
            return;
        }
        if(!f&&root->left){
            m[root->left]=root;
            dfs(root->left,r,m);
        }
        if(!f&&root->right){
            m[root->right]=root;
            dfs(root->right,r,m);
        }
    }
};
