class Solution {
public:
    void dfs_helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited){
        visited[i][j] = 1;
        int n = mat.size(), m = mat[0].size();
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        for (int k=0 ; k<4 ; k++){
            int n_row = i + row[k], n_col = j + col[k];
            if(n_row < 0 || n_row >= n || n_col < 0 || n_col >= m || mat[n_row][n_col] != 0 || visited[n_row][n_col]) continue;
            dfs_helper(n_row, n_col, mat, visited);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3, vector<int>(n*3, 0));
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == '/') {
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }
        int count = 0;
        vector<vector<int>> visited(n*3, vector<int>(n*3, 0));
        for(int i=0 ; i<n*3 ; i++){
            for(int j=0 ; j<n*3 ; j++){
                if(mat[i][j] == 0 && !visited[i][j]){
                    count++;
                    dfs_helper(i, j, mat, visited);
                }
            }
        }
        return count;
    }
};