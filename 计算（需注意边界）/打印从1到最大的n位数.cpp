输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数

链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max=pow(10,n);
        vector<int> re(--max,0);
        while(max)
        re[max]=max--;//这里右面不论是--max还是max--执行完后左边的max都会-1，注意。
        return re;
    }
};
