class Solution {
public:
    void dfs(vector<vector<char>>& b, int i, int j) {
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != 'O') return;
        b[i][j] = '#'; 
        dfs(b, i+1, j);
        dfs(b, i-1, j);
        dfs(b, i, j+1);
        dfs(b, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        // 1. Mark all border-connected O's as safe
        for (int i=0;i<m;i++) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for (int j=0;j<n;j++) {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        // 2. Convert inside O → X, safe # → O
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='#') board[i][j]='O';
    }
};
