链接：https://www.nowcoder.com/questionTerminal/11ee0516a988421abf40b315a2b28d08?f=discussion
来源：牛客网

现在有107个用户，编号为1- 107，现在已知有m对关系，每一对关系给你两个数x和y，代表编号为x的用户和编号为y的用户是在一个圈子中，例如：A和B在一个圈子中，B和C在一个圈子中，那么A,B,C就在一个圈子中。现在想知道最多的一个圈子内有多少个用户。 

输入描述:
第一行输入一个整数T，接下来有T组测试数据。
对于每一组测试数据：第一行输入1个整数n，代表有n对关系。
接下来n行，每一行输入两个数x和y，代表编号为x和编号为y的用户在同一个圈子里。
1 ≤ T ≤ 10
1 ≤ n ≤ 105
1 ≤ x, y ≤ 107


输出描述:
对于每组数据，输出一个答案代表一个圈子内的最多人数

//连通性质的题都可以用并查集。
#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> father;//由于用户id数字上限很高，避免浪费内存，使用了map而不是vector来记录并查集结果。
unordered_map<int, int> cnt;

int find(int a){
    if(!father.count(a)){//使用了map，所以不存在时要先创建，其他步骤和使用vector时一致。
        father[a]=a;
        return a;
    }
    else
    return a==father[a]?a:father[a]=find(father[a]);//因为用户id上限很高，所以一定要路径压缩。
}

void merge(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb)
        father[fb]=fa;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int re=0;
        cin>>n;
        int b,c;
        while(n--){
            cin>>b>>c;
            merge(b,c);
        }
        for(auto it=father.begin();it!=father.end();it++){
            int a=find(it->second);
            cnt[a]++;
            re=max(re,cnt[a]);
        }
        cout<<re<<endl;
        father.clear();
        cnt.clear();
    }
}
