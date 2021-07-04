定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次

链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof

//需要一个辅助数组记录存储到该位置时栈内的最小值。
class MinStack {
    vector<int> a,minele;
    int index=-1;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        a.push_back(x);
        index++;
        if(minele.empty()){
            minele.push_back(x);
        }
        else{
            minele.push_back(x<minele[index-1]?x:minele[index-1]);
        }
    }
    
    void pop() {
        if(index<0)
        return;
        a.pop_back();
        minele.pop_back();
        index--;
    }
    
    int top() {
        return a[index];
    }
    
    int min() {
        return minele[index];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
