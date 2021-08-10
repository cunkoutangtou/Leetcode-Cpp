链接：https://www.nowcoder.com/questionTerminal/7cd9a140387e455a972e8fea0e74be2c
来源：牛客网

由于业绩优秀，公司给小Q放了 n 天的假，身为工作狂的小Q打算在在假期中工作、锻炼或者休息。他有个奇怪的习惯：不会连续两天工作或锻炼。只有当公司营业时，小Q才能去工作，只有当健身房营业时，小Q才能去健身，小Q一天只能干一件事。给出假期中公司，健身房的营业情况，求小Q最少需要休息几天。

输入描述:
第一行一个整数 n(1\leq n\leq 100000)n(1≤n≤100000) 表示放假天数
第二行 n 个数 每个数为0或1,第 i 个数表示公司在第 i 天是否营业
第三行 n 个数 每个数为0或1,第 i 个数表示健身房在第 i 天是否营业
（1为营业 0为不营业）


输出描述:
一个整数，表示小Q休息的最少天数
示例1
输入
4
1 1 0 0
0 1 1 0
输出
2
说明
小Q可以在第一天工作，第二天或第三天健身，小Q最少休息2天

//三行dp分别代表第i天休息工作还是锻炼时当前最小的休息天数。
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    int dp[3][n+1];
    int work[n],exer[n];
    for(int i=0;i<n;i++){
        cin>>work[i];
    }
    for(int i=0;i<n;i++){
        cin>>exer[i];
    }
    memset(dp,0x3f,sizeof(dp));//每个字节都放一个最大的数
    dp[0][0]=0;
    dp[1][0]=0;
    dp[2][0]=0;
    for(int i=1;i<=n;i++){
        if(work[i-1])//今天可以工作的话，最小取值就由另外两项的最小值决定。
            dp[1][i]=min(dp[0][i-1],dp[2][i-1]);
        if(exer[i-1])
            dp[2][i]=min(dp[0][i-1],dp[1][i-1]);
        dp[0][i]=min(dp[0][i-1],min(dp[1][i-1],dp[2][i-1]))+1;//每天一定是可以休息的，休息则休息天数+1.
    }
    cout<<min(dp[0][n],min(dp[1][n],dp[2][n]));
    return 0;
}
