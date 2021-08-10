链接：https://www.nowcoder.com/questionTerminal/61e1e66e39f348cdb6495de91ac36a41
来源：牛客网

小Q在进行一场竞技游戏,这场游戏的胜负关键就在于能否能争夺一条长度为L的河道,即可以看作是[0,L]的一条数轴。
这款竞技游戏当中有n个可以提供视野的道具−真视守卫,第i个真视守卫能够覆盖区间[xi,yi]。现在小Q想知道至少用几个真视守卫就可以覆盖整段河道。 

输入描述:
输入包括n+1行。

第一行包括两个正整数n和L(1<=n<=105,1<=L<=109)

接下来的n行,每行两个正整数xi,yi(0<=xi<=yi<=109),表示第i个真视守卫覆盖的区间。 



输出描述:
一个整数，表示最少需要的真视守卫数量, 如果无解, 输出-1。
示例1
输入
4 6
3 6
2 4
0 2
4 7
输出
3

//双指针，在当前起始位置合法的情况下不断找最右面能到达的地方。
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,L;
    cin>>n>>L;
    typedef pair<int,int> pii;
    vector<pii> co;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        co.push_back({x,y});
    }
    sort(co.begin(),co.end(),[](pii a,pii b){//先按左端点排序，左端点一样则按右端点排序
        return a.first<b.first||(a.first==b.first&&a.second<b.second);
    });
    int cnt=0,l=0,r=0,i=0;
    while(r<L){
        while(i<n&&co[i].first<=l){//每次要找到最右面能到的地方
            if(co[i].second>r)
                r=co[i].second;
            i++;
        }
        cnt++;
        l=r;
        if(i==n&&r<L){//如果全部端点遍历完毕还没找到超过最右的端点，则返回-1.
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}
