class Solution {
public:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        vector<int> nums(10, 0);
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || nums[num]++) return false; 
                if (i == 0) sum += num;  
            }
        }
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < 3; ++j) {
                rowSum += grid[row + i][col + j];
                colSum += grid[row + j][col + i]; 
            }
            if (rowSum != sum || colSum != sum) return false;
        }
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) return false;
        if (grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2] != sum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (isMagicSquare(grid, i, j)) count++; }}
        return count;
    }
};