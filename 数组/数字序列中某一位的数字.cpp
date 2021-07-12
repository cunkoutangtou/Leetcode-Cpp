数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
 

限制：

0 <= n < 2^31

链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof

//找规律，从两位数开始只要满足n>基数*位数就继续在下一个位长度内寻找。
class Solution {
public:
    int findNthDigit(int n) {
        if(n>=10)
        n-=10;
        else
        return n;//不足两位数直接返回
        long t=90;//两位数以上一定是9*10^(i-1)的形式递增，两位数有90个，三位数有900个……。
        int i=2;//代表当前是在几位数内寻找
        while(n>t*i){
            n-=t*i;
            t*=10;
            i++;
        }
        t=n/i+pow(10,i-1);//n/i代表当前位数内的第几个数
        int j=n%i;//代表当前数字内的第几位
        j=i-1-j;//转换成从右往左数要跳过几个数。
        while(j--)
        t/=10;
        return t%10;
    }
};
