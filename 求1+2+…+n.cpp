求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
 

限制：

1 <= n <= 10000

链接：https://leetcode-cn.com/problems/qiu-12n-lcof

//使用构造函数和静态变量实现累加。
class temp{
    public:
    temp(){
        ++n;
        sum+=n;
    }
    static int getsum(){
        return sum;
    }
    private:
    static int sum;
    static int n;
};
int temp::sum=0;
int temp::n=0;
class Solution {
public:
    int sumNums(int n) {
        temp *t=new temp[n];
        return temp::getsum();
    }
};
//使用虚函数实现，和定义两个函数指针的效果其实一样。
class A{
    public:
    virtual int Sum(int n){
        return 0;
    } 
};
A *arr[2];
class B:public A{
    public:
    virtual int Sum(int n){
        return arr[!!n]->Sum(n-1)+n;//!!n将n转换为bool值。
    }
};
class Solution {
public:
    int sumNums(int n) {
        arr[0]=new A();
        arr[1]=new B();
        return arr[1]->Sum(n);
    }
};
