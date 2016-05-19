class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int len = i / 2, j = 0;
            while (j < len)
            {
                dp[i] += (2 * dp[j] * dp[i - j - 1]);
                j++;
            }
            if ((2 * j + 1) == i)
                dp[i] += dp[j] * dp[j];
        }
        return dp[n];
    }
};