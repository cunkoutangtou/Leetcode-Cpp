给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

 

示例 1:



输入: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
输出: 6
解释: 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
示例 2:

输入: grid = [[0,0,0,0,0,0,0,0]]
输出: 0
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1

链接：https://leetcode-cn.com/problems/ZL6zAn

//利用并查集，对不同区块分类，然后统计每个区块中的1的个数。
class Solution {
    vector<int> fa;
    void init(int n){
        fa.resize(n);
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int a,int b){
        fa[find(a)]=find(b);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size(),re=0;
        vector<int> help(m*n,0);
        init(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                        if (i > 0 && grid[i - 1][j] == 1)
                            merge(n * i + j, n * (i - 1) + j);
                        if (i < m - 1 && grid[i + 1][j] == 1)
                            merge(n * i + j, n * (i + 1) + j);
                        if (j > 0 && grid[i][j - 1] == 1)
                            merge(n * i + j, n * i + j - 1);
                        if (j < n - 1 && grid[i][j + 1] == 1)
                            merge(n * i + j, n * i + j + 1);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            int temp=find(i*n+j);
            if(grid[i][j]==1)
            help[temp]++;
            re=max(re,help[temp]);
            }
        }
        return re;
    }
};

//遍历矩阵，永远可以相信dfs;
class Solution {
    int m,n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        int maxa=0,cura=0; 
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> sign(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!sign[i][j]&&grid[i][j]==1){
                    cura=0;
                    dfs(grid,sign,i,j,cura);
                    maxa=max(maxa,cura);
                }
            }
        }
        return maxa;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& sign,int x,int y,int &cura){
        if(sign[x][y])
        return;
        //注意这里是需要统计个数，一个位置永远只会被访问一次，所以不用回溯。
        cura++;
        sign[x][y]=1;
        if(x<m-1&&grid[x+1][y]==1)
        dfs(grid,sign,x+1,y,cura); 
        if(x>0&&grid[x-1][y]==1)
        dfs(grid,sign,x-1,y,cura); 
        if(y<n-1&&grid[x][y+1]==1)
        dfs(grid,sign,x,y+1,cura); 
        if(y>0&&grid[x][y-1]==1)
        dfs(grid,sign,x,y-1,cura); 
    }
};
