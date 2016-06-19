class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size <= 1)  return 0;
        vector<vector<int>> dp(2, vector<int>(size, 0));
        int cur = 0, next = 1;
        if (k > size / 2)
        {
            int res = 0;
            for (int i = 1; i < size; i++)
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }
        for (int i = 0; i < k; i++)
        {
            int maxProfit = dp[cur][0] - prices[0];
            for (int j = 1; j < size; j++)
            {
                dp[next][j] =  max(dp[next][j - 1], maxProfit + prices[j]);
                maxProfit = max(maxProfit, dp[cur][j] - prices[j]);
            }
            swap(cur, next);
        }
        
        return dp[cur][size - 1];
    }
};