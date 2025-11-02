class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); 
        // 0 = empty, 1 = guard, 2 = wall, 3 = guarded

        for (auto &g : guards) grid[g[0]][g[1]] = 1;
        for (auto &w : walls) grid[w[0]][w[1]] = 2;

        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Mark guarded cells in 4 directions for each guard
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            for (auto &d : dirs) {
                int i = x + d.first, j = y + d.second;
                while (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 2 && grid[i][j] != 1) {
                    if (grid[i][j] == 0) grid[i][j] = 3; // mark guarded
                    i += d.first;
                    j += d.second;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++count;

        return count;
    }
};
