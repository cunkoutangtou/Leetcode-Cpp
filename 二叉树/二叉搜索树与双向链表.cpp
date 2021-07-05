输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 

为了让您更好地理解问题，以下面的二叉搜索树为例：

 



 

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

 



 

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。


链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
//利用二叉搜索树中序遍历是一个递增序列的性质，保存上一个访问节点的地址，在每个节点处将该结点的左指针连接到上个节点，上个结点的右指针连接到该节点，然后last=root。
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
        return root;
        Node *last=nullptr;
        inorder(root,last);
        Node *head=last;
        while(head->left)
        head=head->left;
        head->left=last;
        last->right=head;
        return head;
    }
    void inorder(Node *root,Node *&last){
        if(root->left)
        inorder(root->left,last);
        if(last!=nullptr)
        last->right=root;
        root->left=last;
        last=root;
        if(root->right)
        inorder(root->right,last);
    }
};
