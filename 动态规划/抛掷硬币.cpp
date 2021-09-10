有一些不规则的硬币。在这些硬币中，prob[i] 表示第 i 枚硬币正面朝上的概率。

请对每一枚硬币抛掷 一次，然后返回正面朝上的硬币数等于 target 的概率。

示例 1：
输入：prob = [0.4], target = 1
输出：0.40000

示例 2：
输入：prob = [0.5,0.5,0.5,0.5,0.5], target = 0
输出：0.03125
 
提示：
1 <= prob.length <= 1000
0 <= prob[i] <= 1
0 <= target <= prob.length
如果答案与标准答案的误差在 10^-5 内，则被视为正确答案。

示例 1：
输入：prob = [0.4], target = 1
输出：0.40000

示例 2：
输入：prob = [0.5,0.5,0.5,0.5,0.5], target = 0
输出：0.03125
 
提示：
1 <= prob.length <= 1000
0 <= prob[i] <= 1
0 <= target <= prob.length
如果答案与标准答案的误差在 10^-5 内，则被视为正确答案。

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/toss-strange-coins

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
    	int n = prob.size(), i, j, k;
    	vector<vector<double>> dp(n+1, vector<double>(target+1, 0.0));
    	dp[0][0] = 1.0;//初始化
    	for(i = 0; i < n; ++i)
    		for(j = 0; j <= min(i,target); ++j)
			{
				   dp[i+1][j] += dp[i][j]*(1-prob[i]);//下一枚是反面,顺着j继续计算即可，因为第j位只能有j个正面。
           if(j+1 <= target)
				      dp[i+1][j+1] += dp[i][j]*(prob[i]);//下一枚是正面，当出现大于上一轮最大j的值时，扩张数组宽度。
			}
		return dp[n][target];
    }
};
