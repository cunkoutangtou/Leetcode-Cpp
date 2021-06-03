实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

链接：https://leetcode-cn.com/problems/powx-n

//快速幂的递归形式，将n次幂拆成两两相乘，对于奇数次幂除2后向下取整再多乘一个x即可
class Solution {
public:
    double myPow(double x, int n) {
        return n>0?po(x,n):1.0/po(x,n);
    }
    double po(double x,int n){
        if(n==0)
        return 1;
        double y=po(x,n/2);
        return n%2==0?y*y:y*y*x;
    }
};
//快速幂的迭代形式，不断将n的二进制右移，只要n的最低位为1就将结果记入
class Solution {
public:
    double myPow(double x, int n) {
        double re=1;
        long long N=abs(n);
        while(N>0){
            if((N&1)==1)
            re*=x;
            x*=x;
            N/=2;//二进制右移
        }
        return n>0?re:1.0/re;
    }
};
