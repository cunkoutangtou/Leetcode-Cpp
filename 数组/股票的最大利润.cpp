假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

限制：

0 <= 数组长度 <= 10^5

链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof

//不断记录当前位置之前的最小值，并计算当前位置与其之差，并与最大差比较。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
        int min=prices[0],mdiff=0,cdiff=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min)
            min=prices[i];
            cdiff=prices[i]-min;
            if(cdiff>mdiff)
            mdiff=cdiff;
        }
        return mdiff;
    }
};
