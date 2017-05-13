class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 1));
        
        for (int i = 1; i < l; i++) {
            for (int j = 0; j < l - i; j++) {
                if (s[j] == s[j + i]) {
                    dp[j][j + i] = (i == 1) ? 2 : dp[j + 1][j + i - 1] + 2;
                } else {
                    dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
                }
            }
        }
        
        return dp[0][l - 1];
    }
};