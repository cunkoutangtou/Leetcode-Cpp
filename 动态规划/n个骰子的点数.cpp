把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 

限制：

1 <= n <= 11

链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof

//前向累加，将上一轮的结果逐渐向后延伸直到满足骰子的最大能组成的数。
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6);
        for(int i=2;i<=n;i++){
            vector<double> tmp(5*i+1,0);//这一轮会有6i-(i-1)个数产生。
            for(int j=0;j<dp.size();j++){
                for(int k=0;k<6;k++){
                    tmp[j+k]+=dp[j]/6;
                }
            }
            dp=tmp;
        }
        return dp;
    }
};
//从后向前算，需要注意骰子个数少一时的最小数为边界。
class Solution {
    int maxvalue=6;
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(maxvalue*n+1,0);
        for(int i=1;i<=maxvalue;i++)
        dp[i]=1;
        for(int i=2;i<=n;i++){
            for(int j=maxvalue*i;j>=i;j--){
                dp[j]=0;//每一轮第j个位置要重新计算，否则就会有重复计算累加
                for(int k=1;k<=maxvalue;k++){
                    if(j-k<i-1)//骰子个数为i-1时的最小能组成的数为i-1
                    break;
                    dp[j]+=dp[j-k];//第j个位置能由哪些数字组成
                }
            }
        }
        vector<double> re;
        int total=pow(maxvalue,n);
        for(int i=n;i<=maxvalue*n;i++){
            re.push_back(1.0*dp[i]/total);
        }
        return re;
    }
};
