//任何两个因子相差都不小于x
//三个质数相乘
int prime[50000];

//四个因数除去1和自己以外，找到两个满足题意的最小质数就ok了
int func(int x){
    int i, j;
    for(i = 1 + x; i < 50000; i++){//找到第一个质数
        if(prime[i] == 0){
            break;
        }
    }
    for(j = i + x; j < 50000; j++){//在i的基础上找第二个质数
        if(prime[j] == 0)
            break;
    }
    return i * j;//返回质数乘积
}
int main(){
    int T;
    cin >> T;
    //筛素数
    memset(prime, 0, sizeof(prime));
    prime[0] = 1;//0不能选
    prime[2] = 0;
    for(int i = 2; i < 50000; i++){//从4开始，因为1,2,3都是质数。
        if(prime[i] == 1) continue;
        for(int j = 2; j * i < 50000; j++){
            prime[j * i] = 1;
        }
    }
    for(int i = 0; i < T; i++){
        int k;
        cin >> k;
        cout<< func(k) << endl;
    }
    return 0;
}
