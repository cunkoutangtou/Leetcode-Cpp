写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
 

提示：

0 <= n <= 100

链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof

//重复子问题多，适合动态规划，由于每个位置只会用一次，所以没必要用一个数组进行保存，前面的位置后面不会再用了，用三个变量即可。
class Solution {
public:
    int fib(int n) {
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        int a=0;
        int b=1;
        int sum=a+b;
        for(int i=2;i<=n;i++){
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        return b;
    }
};
