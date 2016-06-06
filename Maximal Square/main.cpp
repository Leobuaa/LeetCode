class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int row = (int) matrix.size();
        if (row <= 0) {
            return res;
        }
        
        int col = (int) matrix[0].size();
        if (col <= 0) {
            return res;
        }
        
        vector<vector<int>> dp(2, vector<int>(col, 0));
        
        for (int i = 0; i < col; i++) {
    		dp[0][i] = matrix[0][i] - '0';
    		res = max(res, dp[0][i]);
    	}

    	for (int i = 1; i < row; i++) {
    		dp[i & 1][0] = matrix[i][0] - '0';
    		for (int j = 1; j < col; j++) {
    		    if (matrix[i][j] == '1') {
        			dp[i & 1][j] = min(min(dp[(i + 1) & 1][j], dp[i & 1][j - 1]), dp[(i + 1) & 1][j - 1]) + 1;
        			res = max(res, dp[i & 1][j]);
    		    } else {
    		        dp[i & 1][j] = 0;
    		    }
    		}
    	}
        
        return res * res;
    }
};