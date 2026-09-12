class Solution {
public:

    bool search(vector<vector<char>>& board, int i, int j, string word,int idx = 0){
        if(idx + 1 == word.size()){
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        char temp = board[i][j];
        board[i][j] = 0;
        if(j-1>=0 && board[i][j-1] == word[idx+1]){ //left
            if(search(board,i,j-1,word,idx+1)) return true;
        }
        if(j+1<cols && board[i][j+1] == word[idx+1]){ //right
            if(search(board,i,j+1,word,idx+1)) return true;
        }
        if(i-1>=0 && board[i-1][j] == word[idx+1]){ //top
            if(search(board,i-1,j,word,idx+1)) return true;
        }
        if(i+1<rows && board[i+1][j] == word[idx+1]){ //down
            if(search(board,i+1,j,word,idx+1)) return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(board[i][j] == word[0]){
                    if(search(board,i,j,word)) return true;
                }
            }
        }
        return false;
    }
};
