class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int size = (int)coins.size();
       vector<long long> dp(amount + 1, INT32_MAX);
       dp[0] = 0; 
       for (int i = 1; i <= amount; i++)
       {
           for (int j = 0; j < size; j++)
           {
               if (i >= coins[j])
               {
                   dp[i] = min(dp[i], dp[i - coins[j]] + 1);
               }
           }
       }
       return dp[amount] >= INT32_MAX ? -1 : dp[amount];
    }
};