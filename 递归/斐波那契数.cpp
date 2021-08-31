斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。

 

示例 1：

输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例 2：

输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
示例 3：

输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 

提示：

0 <= n <= 30

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number

//矩阵快速幂
class Solution {
public:
    typedef vector<vector<int>> vvi;
    int fib(int n) {
        if(n<2)
        return n;
        vvi re={{1,1},{1,0}};
        re=m_pow(re,n-1);//注意n=2时只需要乘一次
        return re[0][0];
    }
    vvi multiply(vvi &mat1,vvi &mat2){
        vvi re{{0,0},{0,0}};
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++){
                re[i][j]=mat1[i][0]*mat2[0][j]+mat1[i][1]*mat2[1][j];
            }   
        return re;     
    }
    vvi m_pow(vvi mat,int n){
        vvi re{{1,0},{0,1}};//相当于矩阵中的1
        while(n){
            if(n&1)
            re=multiply(re,mat);
            n>>=1;
            mat=multiply(mat,mat);
        }
        return re;
    }
};
