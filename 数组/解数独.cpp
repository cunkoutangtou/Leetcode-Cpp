/*编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

 

示例：


输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：


 

提示：

board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
题目数据 保证 输入数独仅有一个解

链接：https://leetcode-cn.com/problems/sudoku-solver*/

//回溯法，事先存储需要填数字的空格spaces，然后在这些空格上回溯。
class Solution {
    bool row[9][9];
    bool col[9][9];
    bool box[9][9];
    vector<pair<int,int>> spaces;
    bool valid=true;
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(box,0,sizeof(box));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                spaces.push_back({i,j});
                else{
                    row[i][board[i][j]-'1']=true;
                    col[j][board[i][j]-'1']=true;
                    box[(i/3)*3+j/3][board[i][j]-'1']=true;
                }
            }
        }
        dfs(board,0);
    }
    void dfs(vector<vector<char>>& board,int pos){
        if(pos==spaces.size()){
            valid=false;
            return;
        }
        auto [i,j]=spaces[pos];
        for(int k=0;k<9&&valid;k++){
            if(!row[i][k]&&!col[j][k]&&!box[(i/3)*3+j/3][k]){
            board[i][j]=k+'1';
            row[i][k]=col[j][k]=box[(i/3)*3+j/3][k]=true;
            dfs(board,pos+1);
            row[i][k]=col[j][k]=box[(i/3)*3+j/3][k]=false;
            }
        }
    }
};
//将二维数组改成位图来记录，使用每个int变量的前27位，划分为3个9位分别记录行、列、小九宫格中已经有的数字。
class Solution {
    int sign[9];
    vector<pair<int,int>> spaces;
    bool valid=true;
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(sign,0,sizeof(sign));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                spaces.push_back({i,j});
                else{
                    int digit=board[i][j]-'1';
                    sign[i]^=1<<digit;
                    sign[j]^=1<<9<<digit;
                    sign[(i/3)*3+j/3]^=1<<9<<9<<digit;
                }
            }
        }
        dfs(board,0);
    }
    void flip(int i,int j,int digit){
        sign[i]^=1<<digit;
        sign[j]^=1<<9<<digit;
        sign[(i/3)*3+j/3]^=1<<9<<9<<digit;
    }
    void dfs(vector<vector<char>>& board,int pos){
        if(pos==spaces.size()){
            valid=false;
            return;
        }
        auto [i,j]=spaces[pos];
        for(int k=0;k<9&&valid;k++){
            if(!(sign[i]&(1<<k))&&!(sign[j]&(1<<9<<k))&&!(sign[(i/3)*3+j/3]&(1<<9<<9<<k))){
            board[i][j]=k+'1';
            flip(i,j,k);
            dfs(board,pos+1);
            flip(i,j,k);
            }
        }
    }
};
