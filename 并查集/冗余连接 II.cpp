在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。

返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

 

示例 1：


输入：edges = [[1,2],[1,3],[2,3]]
输出：[2,3]
示例 2：


输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
输出：[4,1]
 

提示：

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection-ii

//对于有向图找多余边与无向图的区别是需要考虑是出现了环，还是一个节点有了两个入度，分类处理即可，其他与无向图没什么区别，就是需要注意并查集合并时的方向。
class Solution {
    vector<int> father;
    int n;
    int find(int a){
        return a==father[a]?father[a]:father[a]=find(father[a]);//边找边合并。
    }
    void merge(int u,int v){//u->v所以v的父节点是u。
        int a=find(u);
        int b=find(v);
        if(a!=b)
        father[v]=u;
    }
    void init(){
        for(int i=1;i<=n;i++)
        father[i]=i;
    }
    bool testNoEdgeTree(vector<vector<int>>& edges,int v){
        init();
        for(int i=0;i<n;i++){
            if(i==v)//跳过删除的边
            continue;
            if(find(edges[i][0])==find(edges[i][1]))//其中有一个节点被另一条边添加过了，即删错边了。
            return false;
            merge(edges[i][0],edges[i][1]);
        }
        return true;//删对边了。
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        if(edges.empty())
        return {};
        n=edges.size();
        father.resize(n+1,0);
        vector<int> indeg(n+1,0);
        vector<int> two;
        for(int i=0;i<n;i++){//统计入度。
            indeg[edges[i][1]]++;
        }
        for(int i=n-1;i>=0;i--){//反向找，即找到数组中后出现的边使某个节点的入度变成了2。
            if(indeg[edges[i][1]]>=2)
            two.push_back(i);//存入这条边
        }
        if(!two.empty()){//由入度为2的节点引起错误。
            return testNoEdgeTree(edges,two[0])?edges[two[0]]:edges[two[1]];//试试删哪条边，two[0]晚于two[1]出现在edges中，所以先测试删除two[0]。
        }
        init();//初始化并查集，为了判断是否为树
        for(int i=0;i<n;i++){//
            if(find(edges[i][0])==find(edges[i][1]))//加入这条边后出现了环，返回这条边即可
            return edges[i];
            merge(edges[i][0],edges[i][1]);
        }
        return {};
    }
};
