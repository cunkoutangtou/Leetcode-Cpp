在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。

给定一个整数n，请返回n位的格雷码，顺序为从0开始。

测试样例：
1
返回：["0","1"]

//从中心扩展，前面的前面加0，后面的前面加1。
class GrayCode {
    vector<string> v{"0","1"};
public:
    vector<string> getGray(int n) {
        if(n==0)
            return {};
        return get(n,1);
    }
    vector<string> get(int n,int index){
        if(index>=n)
            return v;
        for(int i=pow(2,index)-1;i>=0;i--){
            v.push_back("1"+v[i]);
            v[i]="0"+v[i];
        }
        return get(n,index+1);
    }
};
