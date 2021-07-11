如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：

最多会对 addNum、findMedian 进行 50000 次调用。

链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof

//使用一个最大堆和一个最小堆，保证最小堆顶的数一定大于最大堆顶的数，并且两个堆的元素个数之差不大于1。
class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxheap.size()>minheap.size()){
        if(maxheap.top()>num){
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else
        minheap.push(num);
        }
        else{
            if(maxheap.empty())
            maxheap.push(num);
            else if(minheap.top()<num){
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else
            maxheap.push(num);
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size())
        return (maxheap.top()+minheap.top())/2.0;
        else
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
