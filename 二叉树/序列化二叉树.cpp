请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof

//需要自己定义编码方式，这里选择使用','分隔不同数字，用'$'代表nullptr，使用先序遍历编码和解码，将先序经历过的所有内容存下来进行序列化，再按照先序将存储内容翻译出来即可反序列化还原二叉树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "$";
        string re;
        int num=root->val;
        while(num){
        re+=num%10+'0';
        num/=10;
        }
        reverse(re.begin(),re.end());
        re+=',';
        re+=serialize(root->left);
        re+=serialize(root->right);
        return re;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return dePreOrder(data,i);
    }
    TreeNode* dePreOrder(string &data,int &i){
        if(data[i]=='$'){
            i++;
            return nullptr;
        }
        string num;
        while(data[i]!=','){
            num+=data[i];
            i++;
        }
        i++;//跳过’,‘
        int n=0;
        for(auto a:num){
            n*=10;
            n+=a-'0';
        }
        TreeNode *node=new TreeNode(n);
        node->left=dePreOrder(data,i);
        node->right=dePreOrder(data,i);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
