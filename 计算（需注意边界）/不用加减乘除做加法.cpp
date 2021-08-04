写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

 

示例:

输入: a = 1, b = 1
输出: 2
 

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数

链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof

//加法器原理，对两数之和与进位分别保存，最后相加。注意二进制相加可用异或代替。
class Solution {
public:
    int add(int a, int b) {
        int num=0,carry=1,sum=0;
        while(carry){
            sum=a^b;
            carry=(unsigned int)(a&b)<<1;
            a=sum;
            b=carry;
        }       
        return sum;
    }
};
