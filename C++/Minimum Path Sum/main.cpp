class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row <= 0) {
            return 0;
        }
        int col = grid[0].size();
        if (col <= 0) {
            return 0;
        }
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        int r = 1, c = 1;
        while (r < row && c < col) {
            for (int i = c; i < col; i++) {
                dp[r][i] = min(dp[r - 1][i], dp[r][i - 1]) + grid[r][i];
            }
            
            for (int i = r + 1; i < row; i++) {
                dp[i][c] = min(dp[i - 1][c], dp[i][c - 1]) + grid[i][c];
            }
            
            r++;
            c++;
        }
        
        return dp[row - 1][col - 1];
    }
};