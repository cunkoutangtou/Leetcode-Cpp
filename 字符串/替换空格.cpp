请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof

//没给空间限制果断用一个辅助字符串存储新的结果。
class Solution {
public:
    string replaceSpace(string s) {
        string re;
        for(auto &a:s){
            if(a==' ')
            re+="%20";
            else
            re+=a;
        }
        return re;
    }
};
