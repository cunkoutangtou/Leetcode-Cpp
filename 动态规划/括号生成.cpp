数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8

链接：https://leetcode-cn.com/problems/generate-parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        dp[1]={"()"};
        string t;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string &s1:dp[j])//遍历所有s1和s2的可能长度，保证j+(i-1-j)=i-1
                    for(string &s2:dp[i-1-j]){
                        t='('+s1+')'+s2;//重点，每增加一个括号，只可能是这种方式增加,不断尝试将前面所有轮的所有结果拆成两部分放到s1和s2处。
                        dp[i].push_back(t);
                    }
            }
        }   
        return dp[n];
    }
};
