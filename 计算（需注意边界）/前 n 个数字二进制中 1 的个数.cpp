给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。

 

示例 1:

输入: n = 2
输出: [0,1,1]
解释: 
0 --> 0
1 --> 1
2 --> 10
示例 2:

输入: n = 5
输出: [0,1,1,2,1,2]
解释:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

说明 :

0 <= n <= 105
 

进阶:

给出时间复杂度为 O(n*sizeof(integer)) 的解答非常容易。但你可以在线性时间 O(n) 内用一趟扫描做到吗？
要求算法的空间复杂度为 O(n) 。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount ）来执行此操作。

链接：https://leetcode-cn.com/problems/w3tCBm

//每个数字统计一遍1的个数。
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re(n+1);
        for(int i=0;i<=n;i++){
            int cnt=0,t=i;
            while(t){
                cnt++;
                t=t&(t-1);//快速消除最低位1的方法。
            }
            re.push_back(cnt);
        }
        return re;
    }
};
//偶数最低位一定为0，所以一定和它右移一位的的数中1的个数相同，奇数上一个数一定为偶数，所以一定比上一个数多1。
class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)
        return {0};
        vector<int> re(n+1);
        for(int i=1;i<=n;i++){
            if(i%2==0)
            re[i]=re[i>>1];
            else{
                re[i]=re[i-1]+1;
            }
        }
        return re;
    }
};
