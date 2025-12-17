class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int rows=grid.size(), cols=grid[0].size();
        function<int(int, int)> dfs=[&](int r, int c)->int{
            if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c]==0) return 0;
            grid[r][c]=0;
            int area=1;
            area+=dfs(r+1,c); // down
            area+=dfs(r-1,c); // up
            area+=dfs(r,c+1); // right
            area+=dfs(r,c-1); // left
            return area;
        };
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1) max_area=max(max_area,dfs(r,c));
            }
        }
        return max_area;
    }
};