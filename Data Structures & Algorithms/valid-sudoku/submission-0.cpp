class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    for(int row = i+1; row<9; row++){
                        if(board[i][j] == board[row][j]){
                            return false;
                        }
                    }
                    for(int col = j+1; col<9; col++){
                        if(board[i][j] == board[i][col]){
                            return false;
                        }
                    }
                    int startRow = (i/3)*3;
                    int startCol = (j/3)*3;
                    for(int row = startRow; row<startRow+3; row++){
                        for(int col = startCol; col<startCol+3; col++){
                            if(row == i && col == j)
                                continue;
                            if(board[i][j] == board[row][col]){
                                return false;
                            }
                        }
                    } 
                }
            }
        }
        return true;
    }
};