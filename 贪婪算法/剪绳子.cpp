
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58

https://leetcode-cn.com/problems/jian-sheng-zi-lcof/

//动态规划，n大于4时都可以看做长度为1,2,3的小段拼接而成，注意在n>=4时处理方式的不同，需要先判断是否n<4。
class Solution {
public:
    int cuttingRope(int n) {
        if(n<4){//n小于4还必须剪一刀，最大长度为n-1.
            return n-1;
        }
        vector<int> dp(n+1,0);
        //n>4的情况下，下面的长度作为子段不减最长。
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(dp[i],dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
};
//贪婪算法，尽可能剪成长度为3的段，然后判断，最后剩下的大小如果为1则拿一个3过来拼成2*2=4，否则返回3的乘积即可，需要证明。
class Solution {
public:
    int cuttingRope(int n) {
        if(n<4){
            return n-1;
        }
        int re=1;
        int length=n/3;
        int ans=n%3;
        if(ans==1)
        return pow(3,length-1)*4;
        else
        return pow(3,length)*(ans==2?2:1);
    }
};
