请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
 

提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures

//使用单调递减栈，每次遇到大于栈顶元素的数值便依次弹出并计算间距。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty())
        return {};
        stack<int> st;
        int n=temperatures.size();
        vector<int> re(n,0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                int cur=st.top();
                st.pop();
                re[cur]=i-cur;               
            }
            st.push(i);
        }
        return re;
    }
};
