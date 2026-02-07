class Solution {
public:
    vector<pair<int,int>> internal;

    void dfs_helper(vector<vector<int>>& grid, int r, int c, int new_color, int original_color){
        int n = grid.size(), m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != original_color) return;
        grid[r][c] = -new_color;
        dfs_helper(grid, r, c + 1, new_color, original_color);
        dfs_helper(grid, r, c - 1, new_color, original_color);
        dfs_helper(grid, r + 1, c, new_color, original_color);
        dfs_helper(grid, r - 1, c, new_color, original_color);
        if(!(r == 0 || c == 0 || r == n - 1 || c == m - 1 
             || grid[r + 1][c] != -new_color 
             || grid[r - 1][c] != -new_color
             || grid[r][c + 1] != -new_color
             || grid[r][c - 1] != -new_color)) internal.push_back({r, c});
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        internal.clear();
        int original_color = grid[row][col];
        if(original_color == color) return grid;
        dfs_helper(grid, row, col, color, original_color);
        for(auto& i : internal) grid[i.first][i.second] = original_color;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] < 0) grid[i][j] *= -1;
            }
        }
        return grid;
    }
};
