给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。



示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
 

提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成

链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof

//回溯法，设两个嵌套循环，将每个位置都作为初始点尝试一下。回溯时先剪枝，判断该位置是否符合要求或者是否已访问过，正常结束就是word全部匹配上了，然后从该位置的四个方向都试一遍。
class Solution {
    int m,n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        if(m*n<word.size())
        return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(bt(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
    bool bt(vector<vector<char>>& board,const string &word,int i,int j,int k){
        if(i>=m||j>=n||j<0||i<0||board[i][j]!=word[k]||board[i][j]==0)
        return false;
        if(k==word.size()-1)
        return true;
        board[i][j]=0;
        int re=bt(board,word,i-1,j,k+1)||bt(board,word,i+1,j,k+1)||bt(board,word,i,j-1,k+1)||bt(board,word,i,j+1,k+1);
        board[i][j]=word[k];
        return re;
    }
};
