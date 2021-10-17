给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4
 

提示：

1 <= heights.length <=105
0 <= heights[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram

//使用单调栈，单调递增。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
        return 0;
        if(heights.size()==1)
        return heights[0];
        stack<int> st;//栈中保证栈顶之下存储的一定是第一个比栈顶小的元素所在的索引，据此即可判断出栈顶元素的左边界。
        heights.insert(heights.begin(),0);//放入哨兵，保证左边界始终一定存在。
        heights.push_back(0);//防止heights递增，保证最后一定能将栈内元素全部弹出。
        int m=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){//不满足递增则处理
                int cur=heights[st.top()];
                st.pop();
                int left=st.top()+1;//宽度计算方式为包含右边界，不包含左边界，从右往左高度减小，宽度增加。
                int right=i-1;
                m=max(m,(right-left+1)*cur);
            }
            st.push(i);
        }
        return m;
    }
};
