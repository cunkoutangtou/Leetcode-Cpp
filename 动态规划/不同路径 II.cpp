一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

 

示例 1：


输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
示例 2：


输入：obstacleGrid = [[0,1],[0,0]]
输出：1
 

提示：

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii

//动态规划，不能走的地方，方案数置0，对于i=0和j=0的一排一列，由于方向没变过，其方案数只要没有障碍物便始终为1.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
        return 0;
        if(obstacleGrid[0][0])
        return 0;
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)
                continue;
                if(obstacleGrid[i][j]){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0&&j>0)
                    dp[0][j]=dp[0][j-1];
                else if(j==0&&i>0)
                    dp[i][0]=dp[i-1][0];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//压缩状态，由于每个位置的元素只由它左边和上边的元素决定，所以可用一个一维数组即可，使用滚动数组的思想。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
        return 0;
        if(obstacleGrid[0][0])
        return 0;
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0]=(obstacleGrid[0][0]==0);//初始为0一切白搭
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]){
                    dp[j]=0;
                    continue;
                }
                if(j>0&&obstacleGrid[i][j]==0)//不更新代表该位置的元素直接保存到下一层，更新时当前d[j]代表从上面过来，dp[j-1]代表从左边过来。
                    dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
