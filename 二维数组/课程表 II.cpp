现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

示例 1:

输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:

输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-ii

//dfs，一条路走到底，只要最后的那个节点出度为0，就可以放入栈，代表拓扑排序最后一个。DFS需要注意有没有坏，在过程中要标记经过的结点。
class Solution {
    vector<vector<int>> edges;
    vector<int> result;
    vector<int> visited;
    bool valid=true; //判断是否有环
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)
        return {};
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(auto &a:prerequisites){
            edges[a[1]].push_back(a[0]);
        }
        for(int i=0;i<numCourses&&valid;i++){
            if(visited[i]==0)
            dfs(i);
        }
        if(!valid)
        return {};
        reverse(result.begin(),result.end());
        return result;
    }
    void dfs(int node){
        visited[node]=1;
        for(auto a:edges[node]){
            if(!valid)
            return;
            if(visited[a]==0)
            dfs(a);
            else if(visited[a]==1){
                valid=false;
                return;
            }
        }
        visited[node]=2;
        result.push_back(node);
        return;
    }
};
//BFS，要统计所有结点的入度，不断将入度为0的节点入队，访问队列中的结点时要注意与它连接的结点入度-1。
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)
        return {};
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses,0),re;
        for(auto &a:prerequisites){
            edges[a[1]].push_back(a[0]);
            indeg[a[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            re.push_back(cur);
            q.pop();
            for(auto a:edges[cur]){
                indeg[a]--;
                if(indeg[a]==0)
                q.push(a);
            }
        }
        if(re.size()!=numCourses)
        return {};
        return re;
    }
};
