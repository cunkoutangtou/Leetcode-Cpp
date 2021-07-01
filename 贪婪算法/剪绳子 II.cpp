给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 

提示：

2 <= n <= 1000

https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/

//本题不适合动态规划，涉及到大数问题，使用动态规划的话中间需要比较当前值是否为最大值，不能取余，会导致最后数非常大，所以需要一个方法在中间就进行处理，所以使用贪心算法。在模1000000007域进行运算，
//需要保证每个计算结果都不会超出域的限制。
class Solution {
    int a=1000000007;
public:
    int cuttingRope(int n) {
        if(n<4){
            return n-1;
        }
        int re=1;
        int length=n/3;
        int ans=n%3;
        if(ans==1)
        return (pow(3,length-1)*4)%a;
        else
        return (pow(3,length)*(ans==2?2:1))%a;
    }
    long long pow(long long x,int y){
        long long re=1;
        while(y>0){
            if(y&1)
            re=(re*x)%a;
            x=(x*x)%a;
            y/=2;
        }
        return re;
    }
};
