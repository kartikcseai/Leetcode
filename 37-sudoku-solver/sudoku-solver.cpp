class Solution {
public:
    bool is_safe(vector<vector<char>>& board, int row, int col, char d){
        for(int j = 0; j < 9; j++) if(board[row][j] == d) return false;
        for(int i = 0; i < 9; i++) if(board[i][col] == d) return false;
        int start_row = (row/3) * 3;
        int start_col = (col/3) * 3;
        for(int i = start_row; i < start_row + 3; i++){
            for(int j = start_col; j < start_col + 3; j++){
                if(board[i][j] == d) return false;
            }
        }
        return true;    
    }
    bool helper_solveSudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        int next_row = row, next_col = col + 1;
        if(next_col == 9){
            next_row = row + 1;
            next_col = 0;
        }
        if(board[row][col] != '.') return helper_solveSudoku(board, next_row, next_col);
        for(char d = '1'; d <= '9'; d++){
            if(is_safe(board, row, col, d)){
                board[row][col] = d;
                if(helper_solveSudoku(board, next_row, next_col)) return true;
                board[row][col] = '.';
            }
        }
        return false;  
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper_solveSudoku(board, 0, 0);
    }
};