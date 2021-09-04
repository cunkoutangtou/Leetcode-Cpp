给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands

//带rank的并查集。
class Solution {
    vector<int> s;
    vector<int> rank;
    int count=0;//记录集合数量
    int find(int a){
        return a==s[a]?s[a]:find(s[a]);
    }
    void combine(int a,int b){
        int ra=find(a);
        int rb=find(b);
        if(ra!=rb){
            if(rank[ra]<rank[rb])//保证rank小的连到rank大的集合上
            swap(ra,rb);
            s[rb]=ra;
            if(rank[ra]==rank[rb])//只有两个集合rank相同时才会使并集后的集合rank+1。
            rank[ra]+=1;
            count--;
        }
    }
    int getcount(){
        return count;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size();
        s.resize(m*n,0);
        rank.resize(m*n,0);
        for(int i=0;i<m*n;i++)//初始化并查集
        s[i]=i;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    grid[i][j]='0';//访问过则置0，减少重复计算
                    if(i>0&&grid[i-1][j]=='1'){
                        combine(i*n+j,(i-1)*n+j);
                    }
                    if(i<m-1&&grid[i+1][j]=='1'){
                        combine(i*n+j,(i+1)*n+j);
                    }
                    if(j>0&&grid[i][j-1]=='1'){
                        combine(i*n+j,i*n+j-1);
                    }
                    if(j<n-1&&grid[i][j+1]=='1'){
                        combine(i*n+j,i*n+j+1);
                    }
                }
            }
        }
        return getcount();
    }
};
//DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size(),re=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    ++re;
                }
            }
        }
        return re;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
            grid[i][j]='0';//由于每个1只需要访问一次，所以访问完置为0即可
            if(i<m-1&&grid[i+1][j]=='1'){//注意四个方向都要考虑
                dfs(grid,i+1,j,m,n);
            }
            if(j<n-1&&grid[i][j+1]=='1'){
                dfs(grid,i,j+1,m,n);
            }
            if(i>0&&grid[i-1][j]=='1'){
                dfs(grid,i-1,j,m,n);
            }
            if(j>0&&grid[i][j-1]=='1'){
                dfs(grid,i,j-1,m,n);
            }
    }
};
//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        return 0;
        int m=grid.size(),n=grid[0].size(),re=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int row=q.front().first,col=q.front().second;
                        q.pop();
                        if(row<m-1&&grid[row+1][col]=='1'){
                            q.push({row+1,col});
                            grid[row+1][col]='0';//注意入队后要立即置0，否则可能会有元素重复入队
                        }
                        if(col<n-1&&grid[row][col+1]=='1'){
                            q.push({row,col+1});
                            grid[row][col+1]='0';
                        }
                        if(row>0&&grid[row-1][col]=='1'){
                            q.push({row-1,col});
                            grid[row-1][col]='0';
                        }
                        if(col>0&&grid[row][col-1]=='1'){
                            q.push({row,col-1});
                            grid[row][col-1]='0';
                        }
                    }
                    re++;
                }
            }
        }
        return re;
    }
};
