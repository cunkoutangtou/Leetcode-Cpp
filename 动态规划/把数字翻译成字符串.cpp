
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231

链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof

//dfs的方式，和回溯法类似，不过每一层是否该往下走的条件很明显，就是num%100>=10&&num%100<=25，所以就没必要先走一步试一试了，可以看做简化的回溯。
//这里从数字的尾端开始dfs是因为有重复子问题，比如12256的到12和256和1,2256->2,256，从尾开始则先处理子问题，不会重复。
class Solution {
public:
    int translateNum(int num) {
        if(num<=9)
        return 1;
        if(num%100>=10&&num%100<=25)
        return translateNum(num/100)+translateNum(num/10);//每一层只需要判断能否往下走就可以了，最终统计的是有多少条从根到叶的路径。
      //如果对每层的数字还需要进行额外的处理，那么可以在这两个的和的基础上加上本层处理的结果。
        else
        return translateNum(num/10);
    }
};

//类似斐波那契数列，只不过这时关心的是num的位数，p代表有0位（没意义，仅为了好理解，一定至少有一位）时该有的可行解个数，q代表有1位时该有的可行解个数。
//从2位开始计算，如果满足则将0位与1位的值相加，只不过不满足条件时，保持i-1的状态数，满足时将i-1与i-2的数加起来。
class Solution {
public:
    int translateNum(int num) {
        int cnt=0;
        string s=to_string(num);
        int p=1,q=1,sum=0;
        for(int i=1;i<s.size();i++){
            if(s.substr(i-1,2)>="10"&&s.substr(i-1,2)<="25")
            sum=p+q;
            else
            sum=q;
            p=q;
            q=sum;
        }
        return q;
    }
};
