输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100


链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof

//画图分析，判断什么条件下一周的上、右、下、左可以被打印出来。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        return {};
        vector<int> re;
        int row=matrix.size(),col=matrix[0].size(),start=0,endx=col-1,endy=row-1;
        while(row>start*2&&col>start*2){//由于每打印一周矩阵长宽都会-2，start既是每一周左上角开始的位置也是这个-2的计数。
            //注意，只有第一步即向右横着走的是必有得，其他的如上->下，右->左，下->上都要验证。
            for(int i=start;i<=endx;i++){
                re.push_back(matrix[start][i]);
            }
            if(endy-start>0){
                for(int i=start+1;i<=endy;i++){
                    re.push_back(matrix[i][endx]);
                }
            }
            if(endy-start>0&&endx-start>0){
                for(int i=endx-1;i>=start;i--){
                    re.push_back(matrix[endy][i]);
                }
            }
            if(endy-start-1>0&&endx-start>0){
                for(int i=endy-1;i>=start+1;i--){
                    re.push_back(matrix[i][start]);
                }
            }
            start++;
            endx--;
            endy--;
        }
        return re;
    }
};
