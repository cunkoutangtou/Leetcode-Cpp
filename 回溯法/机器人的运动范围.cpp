地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof

//只有一个起点，深度优先向右和下方一个一个走即可。
class Solution {
    int row,col;
    vector<vector<int>> sign;
public:
    int movingCount(int m, int n, int k) {
        row=m;
        col=n;
        sign.resize(m,vector<int>(n,0));
        int num=0;
        bt(0,0,k,num);
        return num;
    }
    void bt(int m,int n,int k,int &num){
        if(!check(m,n,k))
        return;
        num+=1;
        sign[m][n]=1;
        bt(m+1,n,k,num);
        bt(m,n+1,k,num);
    }
    bool check(int m,int n,int k){
        int sum1=0,sum2=0;
        int i=m,j=n;
        while(m){
            sum1+=m%10;
            m/=10;            
        }
        while(n){
            sum2+=n%10;
            n/=10;            
        }
        if(sum1+sum2<=k&&i<row&&i>=0&&j<col&&j>=0&&sign[i][j]==0)
        return true;
        else
        return false;
    }
};
