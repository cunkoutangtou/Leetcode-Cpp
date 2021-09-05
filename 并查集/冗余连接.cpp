树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

 

示例 1：



输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]
示例 2：



输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
 

提示:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
edges 中无重复元素
给定的图是连通的 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection

//连通则可以归为一类，只要判断两个端点是否已在同一类即可判断是否会出现环或者重复边。
class Solution {
    vector<int> help;
    vector<int> rank;
    int find(int a){
        return a==help[a]?help[a]:find(help[a]);
    }
    void unite(int a,int b){
        int ra=find(a),rb=find(b);
        if(ra!=rb){
            if(rank[ra]<rank[rb]){
                ra=ra+rb;
                rb=ra-rb;
                ra=ra-rb;
            }
            help[rb]=ra;
            if(rank[ra]==rank[rb])
            rank[ra]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.empty())
        return {};
        int n=edges.size();
        help.resize(2*n);
        for(int i=0;i<2*n;i++){
            help[i]=i;
        }
        vector<int> re(2,0);
        rank.resize(2*n,0);
        for(int i=0;i<n;i++){
            if(find(edges[i][0])==find(edges[i][1])){
                re[0]=edges[i][0];
                re[1]=edges[i][1];
            }
            else
            unite(edges[i][0],edges[i][1]);
        }
        return re;
    }
};
