在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

 

示例 1：

输入：A = [[0,1],[1,0]]
输出：1
示例 2：

输入：A = [[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
 

提示：

2 <= A.length == A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-bridge

//先进行扫描，然后用DFS把整个岛标记出来，再用BFS找最短距离。grid中2代表标记出来的岛，1代表其它的岛，0代表水，3代表扫描过的位置。
class Solution {
    queue<pair<int,int>> q;
    int direction[5]{-1,0,1,0,-1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size();
        bool r=true;
        for(int i=0;i<m&&r;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dfs(grid,i,j,m,n);
                    r=false;
                    break;
                }
            }
        }
        int level=0;
        int x=0,y=0;
        while(!q.empty()){
            level++;//记录BFS层数
            int nump=q.size();
            while(nump--){
                auto [r,c]=q.front();q.pop();
                for(int i=0;i<4;i++){//减少手打内容，自动完成四个方向的搜索。
                    x=r+direction[i];
                    y=c+direction[i+1];
                    if(x>=0&&x<m&&y>=0&&y<n){
                        if(grid[x][y]==0){//记录扫过的位置
                            grid[x][y]=3;
                            q.push({x,y});
                        }
                        else if(grid[x][y]==1){//到达另一座岛
                            return level;
                        }
                    }
                }
            }
        }
        return level;
    }
    void dfs(vector<vector<int>> &grid,int x,int y,int m,int n){
        if(x<0||x>=m||y<0||y>=n||grid[x][y]==2||grid[x][y]==3)
        return;
        if(grid[x][y]==0){//将岛周围的水域先存入队列。
            grid[x][y]=3;
            q.push({x,y});
            return;
        }
        grid[x][y]=2;
        dfs(grid,x-1,y,m,n);
        dfs(grid,x+1,y,m,n);
        dfs(grid,x,y-1,m,n);
        dfs(grid,x,y+1,m,n);
    }
};
