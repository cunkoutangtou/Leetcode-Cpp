输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

 

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
 

提示：

数组长度 <= 1000

链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof

//如果空序列合法的写法
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())
        return true;
        int i=0,l=postorder.size();
        vector<int> v1,v2;
        while(i<l-1){
            if(postorder[i]>postorder[l-1])
            break;
            v1.push_back(postorder[i]);
            i++;
        }
        int j=i;
        while(j<l-1){
            if(postorder[j]<postorder[l-1])
            return false;
            v2.push_back(postorder[j]);
            j++;
        }
        return verifyPostorder(v1)&&verifyPostorder(v2);
    }
};
//空序列不合法的写法。
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())
        return false;
        int i=0,l=postorder.size();
        vector<int> v1,v2;
        while(i<l-1){
            if(postorder[i]>postorder[l-1])
            break;
            v1.push_back(postorder[i]);
            i++;
        }
        int j=i;
        while(j<l-1){
            if(postorder[j]<postorder[l-1])
            return false;
            v2.push_back(postorder[j]);
            j++;
        }
        bool left=true,right=true;
        if(i)
        left=verifyPostorder(v1);
        if(j>i)
        right=verifyPostorder(v2);
        return left&&right;
    }
};
