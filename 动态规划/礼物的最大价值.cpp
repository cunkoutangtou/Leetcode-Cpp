在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200

链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof

//动态规划，由于每次更新只需要当前位置的左侧和上侧的值，即更新j需要j-1与旧的j的位置的值，所以用一个数组保存动态规划的结果即可。
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left=0,up=0;
                if(j)//从每行第二个位置开始才需要左边的值来更新。
                left=dp[j-1];
                if(i)//从第二行开始才需要上边的值。
                up=dp[j];
                dp[j]=max(left,up)+grid[i][j];
            }
        }
        return dp[n-1];
    }
};
