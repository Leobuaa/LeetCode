class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int length = s.length();
        if (length == 0)
            return true;
        vector<bool> dp(length + 1);
        dp[0] = true;
        fill(dp.begin() + 1, dp.end() + 1, false);
        
        for (int i = 1; i <= length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[length];
    }
};