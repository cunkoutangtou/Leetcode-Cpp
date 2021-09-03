给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        return 0;
        int m=matrix.size(),n=matrix[0].size(),re=0;
        vector<int> h(n+2,0);
        for(int i=0;i<m;i++){//每一层分别存储一个数组，数字代表高度，转化为柱状图
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                ++h[j+1];
                else
                h[j+1]=0;
            }
            stack<int> st; 
            for(int j=0;j<n+2;j++){//求柱状图拼成的最大矩形
                while(!st.empty()&&h[st.top()]>h[j]){
                    int cur=h[st.top()];
                    st.pop();
                    int left=st.top()+1;
                    int right=j-1;
                    re=max(re,(right-left+1)*cur);
                }
                st.push(j);
            }
        }
        return re;
    }
};
