链接：https://www.nowcoder.com/questionTerminal/e8423459fd554a3984cc1d7b6059c0c9?f=discussion
来源：牛客网

求抛物线与直线所围成的封闭图形面积.若图形不存在,则输出0
（具体问题包括图片到网址内去看）

输入描述:
第一行输入一个正整数T.表示测试数据组数.

接下来每行输入三个整数A , B和 C.

1<=T<=1000
1<=A,B<=100
-100<=C<=100


输出描述:
每组测试数据输出一个答案.在<1e-4范围内都视为正确输出.
示例1
输入
1
1 1 -6
输出
31.2481110540

#include<bits/stdc++.h>
using namespace std;

//就是数学题推导
int main(){
    int T;
    cin>>T;

    while(T--){
        int A,B,C;
        cin>>A>>B>>C;

        int a = B*B, b = 2*B*C-2*A, c = C*C;//将直线代入椭圆方程解得三个参数。
        int delta = b*b - 4*a*c;//判断一元二次方程根的个数。
        if(delta<=0){ //若交点小于两个，直接返回0
            cout<<"0"<<endl;
        }else{
            double x1 = (-b + sqrt(delta))/(2*a);//求根公式
            double x2 = (-b - sqrt(delta))/(2*a);

            // 易知y1大于y2(B > 0, x1 > 0, x2 > 0)
            double y1 = B*x1 + C;
            double y2 = B*x2 + C;

            double res = (y1*y1-y2*y2)/(2*B) + (y2-y1)*C/B + (y2*y2*y2-y1*y1*y1)/(6*A);//翻转图形，将y当作自变量求定积分。

            cout<<res<<endl;
        }
    }

    return 0;
}
