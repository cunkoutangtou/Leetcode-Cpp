输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。


链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof

//创建辅助栈，当前弹出的元素与辅助栈顶元素不同则按照压入顺序不断压入栈，如果全部压完栈顶元素与弹出元素仍不同，则返回false。
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty()&&popped.empty())
        return true;
        if(pushed.empty()||popped.empty())
        return false;
        int l1=pushed.size(),l2=popped.size();
        if(l1!=l2)
        return false;
        stack<int> s;
        int i=0,j=0;
        while(j<l2){
            while(s.empty()||(i<l1&&s.top()!=popped[j]))
            s.push(pushed[i++]);
            if(s.top()!=popped[j])
            return false;
            while(!s.empty()&&j<l2&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return true;
    }
};
