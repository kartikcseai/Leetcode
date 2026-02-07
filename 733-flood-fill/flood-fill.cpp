class Solution {
public:
    void dfs_helper(vector<vector<int>>& image, int curr_row, int curr_col, int initial_colour, int new_colour){
        int n = image.size(), m = image[0].size();
        if(curr_row < 0 || curr_col < 0 || curr_col >= m || curr_row >= n) return;
        if(image[curr_row][curr_col] != initial_colour) return;
        image[curr_row][curr_col] = new_colour;
        dfs_helper(image, curr_row, curr_col + 1, initial_colour, new_colour);
        dfs_helper(image, curr_row, curr_col - 1, initial_colour, new_colour);
        dfs_helper(image, curr_row + 1, curr_col, initial_colour, new_colour);
        dfs_helper(image, curr_row - 1, curr_col, initial_colour, new_colour);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        dfs_helper(image, sr, sc, image[sr][sc], color);
        return image;
    }
};