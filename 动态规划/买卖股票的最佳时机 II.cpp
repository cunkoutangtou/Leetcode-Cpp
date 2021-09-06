给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

//动态规划，记录今天的收益。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));//第二维为0代表没有持有股票，为1代表持有了。
        dp[0][0]=0;
        dp[0][1]=-prices[0];//购买股票的花费。
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//今天未持有，最大收益由前一天没持有和前一天持有今天卖出了决定。
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//今天持有，最大收益由前一天持有和前一天没持有但今天购买了决定。
        }
        return dp[n-1][0];//最后一定是没持有的，持有也要卖出才可能最大。
    }
};
//由于每个新状态只由前1个状态决定，所以只需要存两个变量记录即可。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
        int n=prices.size();
        int dp1=0,dp2=0;
        dp1=0;
        dp2=-prices[0];
        for(int i=1;i<n;i++){
            dp1=max(dp1,dp2+prices[i]);
            dp2=max(dp2,dp1-prices[i]);
        }
        return dp1;
    }
};
//前向差分，然后贪心，只要今天相比昨天升了，就卖。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
        int n=prices.size();
        int re=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
            re+=(prices[i]-prices[i-1]);
        }
        return re;
    }
};
