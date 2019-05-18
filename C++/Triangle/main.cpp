class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowNum = (int)triangle.size();
        if (rowNum <= 0) {
            return 0;
        }
        
        if (rowNum == 1) {
            return triangle[0][0];
        }
        vector<vector<int>> dp(2, vector<int>(rowNum, 0));
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
        
        for (int i = 2; i < rowNum; i++) {
            dp[i & 1][0] = dp[(i + 1) & 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                dp[i & 1][j] = min(dp[(i + 1) & 1][j - 1], dp[(i + 1) & 1][j]) + triangle[i][j];
            }
            dp[i & 1][i] = dp[(i + 1) & 1][i - 1] + triangle[i][i];
        }
        
        int flag = ((rowNum - 1) & 1);
        int res = dp[flag][0];
        for (int i = 1; i < rowNum; i++) {
            res = min(dp[flag][i], res);
        }
        return res;
    }
};