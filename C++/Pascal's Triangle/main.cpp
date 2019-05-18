class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        if (numRows < 1)    return dp;
        dp.push_back(vector<int>{1});
        for (int i = 1; i < numRows; i++)
        {
            dp.push_back(vector<int>{1});
            for (int j = 1; j < i; j++)
                dp[i].push_back(dp[i - 1][j] + dp[i - 1][j - 1]);
            dp[i].push_back(1);
        }
        return dp;
    }
};