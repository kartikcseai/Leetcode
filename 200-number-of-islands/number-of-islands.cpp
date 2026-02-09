class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int connected_components = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '0') continue;
                connected_components++;
                grid[r][c] = '0';
                queue<pair<int, int>> q;
                q.push({r,c});
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    int curr_row = curr.first;
                    int curr_col = curr.second;
                    if(curr_row - 1 >= 0 && grid[curr_row - 1][curr_col] == '1'){
                        q.push({curr_row - 1, curr_col});
                        grid[curr_row - 1][curr_col] = '0';
                    }
                    if(curr_row + 1 < rows && grid[curr_row + 1][curr_col] == '1'){
                        q.push({curr_row + 1, curr_col});
                        grid[curr_row + 1][curr_col] = '0';
                    }
                    if(curr_col - 1 >= 0 && grid[curr_row][curr_col - 1] == '1'){
                        q.push({curr_row, curr_col - 1});
                        grid[curr_row][curr_col - 1] = '0';
                    }
                    if(curr_col + 1 < cols && grid[curr_row][curr_col + 1] == '1'){
                        q.push({curr_row, curr_col + 1});
                        grid[curr_row][curr_col + 1] = '0';
                    }
                }
            }
        }
        return connected_components;
    }
};