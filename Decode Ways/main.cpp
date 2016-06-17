class Solution {
public:
    int numDecodings(string s) {
        int len = (int)s.length();
        if (len == 0) {
            return 0;
        }
        
        for (int i = 0; i < len; i++)
        {
            if (s[i] != '0') {
                continue;
            } else if ( i == 0 || !(s[i - 1] == '1' || s[i - 1] == '2')) {
                return 0;
            }
        }
        
        vector<int> dp(len, 0);
        dp[0] = 1;
        
        if (len == 1) {
            return dp[0];
        }
        
        if (((s[0] == '1') && (s[1] >= '1')) || ((s[0] == '2') && (s[1] <= '6') && (s[1] >= '1'))) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }
        
        for (int i = 2; i < len; i++) {
            if (s[i] == '0') {
                dp[i] = dp[i - 2];
            } else if (((s[i - 1] == '1') && (s[i] >= '1')) || ((s[i - 1] == '2') && (s[i] <= '6') && (s[i] >= '1'))) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len - 1];
    }

    // A better one and more clear solution
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }
        
        int dp1 = 1, dp2 = 1, res = 0;
        
        for (int i = 1; i < n; i++) {
            if (isValid(s[i]) && isValid(s[i - 1], s[i])) {
                res = dp1 + dp2;
            }
            
            if (!isValid(s[i]) && isValid(s[i - 1], s[i])) {
                res = dp2;
            }
            
            if (isValid(s[i]) && !isValid(s[i - 1], s[i])) {
                res = dp1;
            }
            
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) {
                return 0;
            }
            
            dp2 = dp1;
            dp1 = res;
        }
        
        return res;
    }
    
    bool isValid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6');
    }
    
    bool isValid (char a) {
        return a != '0';
    }
};