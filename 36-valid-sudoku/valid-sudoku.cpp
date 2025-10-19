class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of numbers seen in row, column, and box
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;

                int num = board[r][c] - '1'; // convert '1'-'9' → 0-8
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check if already seen in row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num])
                    return false;

                // Mark as seen
                rows[r][num] = 1;
                cols[c][num] = 1;
                boxes[boxIndex][num] = 1;
            }
        }
        return true;
    }
};
