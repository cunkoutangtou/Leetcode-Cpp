给定数组b为n*2的数组，如果其中的每对元素不存在父子或者祖孙关系，则交换。
class Solution {
public:
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, int> fa;
    bool judge(TreeNode* a, int val){
        if(!a) return false;
        if(a -> val == val) return true;
        return judge(a -> left, val) || judge(a -> right, val);
    }

    bool isFather(TreeNode* a, TreeNode* b){
        return judge(a, b -> val) || judge(b, a -> val);
    }

    void swap(vector<int>& v){
        if(isFather(mp[v[0]], mp[v[1]]))
            return;
        TreeNode* a = mp[fa[v[0]]];
        TreeNode* ason = mp[v[0]];
        TreeNode* b = mp[fa[v[1]]];
        TreeNode* bson = mp[v[1]];
        
        //下面一大段其实就是交换a,b的孩子，只不过要讨论是左子树还是右子树
        if(a -> left == ason && b -> left == bson){
            a -> left = bson;
            fa[bson -> val] = a -> val;
            b -> left = ason;
            fa[ason -> val] = b -> val;
        } else if(a -> left == ason && b -> right == bson) {
            a->left = bson;
            fa[bson->val] = a->val;
            b->right = ason;
            fa[ason->val] = b->val;
        } else if(a -> right == ason && b -> left == bson) {
            a->right = bson;
            fa[bson->val] = a->val;
            b->left = ason;
            fa[ason->val] = b->val;
        } else if(a -> right == ason && b -> right == bson){
            a -> right = bson;
            fa[bson -> val] = a -> val;
            b -> right = ason;
            fa[ason -> val] = b -> val;
        }
    }
    void dfs(TreeNode* root, int f){
        if(!root) return;
        mp[root -> val] = root;//记录val和节点的映射关系
        fa[root -> val] = f;  //记录节点父亲
        dfs(root -> left, root -> val);
        dfs(root -> right, root -> val);
    }
    TreeNode* solve(TreeNode* root, vector<vector<int> >& b) {
        // write code here
        dfs(root, -1);
        for(auto& v : b){
            swap(v);
        }
        return root;
    }
};
