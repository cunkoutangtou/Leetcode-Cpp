请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof

//一个队列可以看成一个可变大小的窗口，用双端队列储存队列中的最大值即可。
class MaxQueue {
    struct a{
        int d;
        int index;
    };
    queue<a> data;
    deque<a> max;
    int i;
public:
    MaxQueue() {
        i=0;
    }
    
    int max_value() {
        if(max.empty())
        return -1;
        return max.front().d;
    }
    
    void push_back(int value) {
        data.push({value,i});
        while(!max.empty()&&value>max.back().d)
        max.pop_back();
        max.push_back({value,i});
        i++;
    }
    
    int pop_front() {
        if(data.empty())
        return -1;
        int t=data.front().d;
        if(data.front().index==max.front().index)
        max.pop_front();
        data.pop();
        return t;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
