我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

链接：https://leetcode-cn.com/problems/chou-shu-lcof

//使用三路归并，丑数一定是由2、3、5乘出来的，所以p2,p3和p5始终指向需要与因子2,3,5相乘的下一个丑数来不断生成丑数。
//可以理解为存在三个数组，其中元素分别由2,3,5产生，p2,p3和p5分别指向各个数组中除了固定的2或3或5以外的另一个因子，
//通过两个因子相乘不断完成这三个数组，并每次将三个数组新产生的最小的元素归入到dp数组中。
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,1);
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(dp[p2]*2==dp[i])
            p2++;
            if(dp[p3]*3==dp[i])
            p3++;
            if(dp[p5]*5==dp[i])
            p5++;
        }
        return dp[n-1];
    }
};
