有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

 

示例 1：


输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
示例 2：


输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
 

提示：

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-provinces

//使用并查集，将所有城市归类。
class Solution {
    vector<int> s;
    int find(int a){
        return a==s[a]?s[a]:find(s[a]);
    }
    void combine(int a,int b){
        s[find(b)]=find(a);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }
        int n=isConnected.size(),re=0;
        s.resize(n);
        for(int i=0;i<n;i++){
            s[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){//无向图，邻接矩阵是关于对角线对称的，所以每行从i+1开始扫描即可。
                if(isConnected[i][j])
                combine(i,j);
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]==i)
            ++re;
        }
        return re;
    }
};
//使用DFS，每次将所有连通的城市走一遍，并且标记访问过。
class Solution {
    vector<int> visited;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }
        int n=isConnected.size(),re=0;
        visited.resize(n,0);
        for(int i=0;i<n;i++){
            if(visited[i])
            continue;
            dfs(isConnected,i,n);
            re++;
        }
        return re;
    }
    void dfs(const vector<vector<int>> &isConnected,int i,int n){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]&&!visited[j]){
                visited[j]=1;
                dfs(isConnected,j,n);//走到了第j个城市，从这继续出发，访问所有连通但没访问过的城市。
            }
        }
    }
};
//BFS，与DFS思路没有本质区别，只不过DFS是竖着把省画出来，BFS是横着。
class Solution {
    vector<int> visited;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }
        int n=isConnected.size(),re=0;
        visited.resize(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(visited[i])
            continue;
            q.push(i);
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                visited[cur]=1;//访问过后置visited为1。
                for(int j=0;j<n;j++){//将与当前节点连接的所有未被访问的节点放入队列。
                    if(isConnected[cur][j]&&!visited[j]){
                        visited[j]=1;
                        q.push(j);
                    }
                }
            }
            re++;
        }
        return re;
    }
};
