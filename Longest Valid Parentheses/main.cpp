class Solution {
public:
    // My solution. It runs 16ms. Not very good.
    int longestValidParentheses(string s) {
       int len = (int)s.length();
       vector<bool> isValid(len, false);
       stack<pair<char, int>> sta;
       for (int i = 0; i < len; i++) {
           if (s[i] == '(') {
               sta.push(make_pair('(', i));
           } else if (!sta.empty()) {
               auto tmp = sta.top();
               sta.pop();
               if (tmp.first == '(') {
                   isValid[i] = isValid[tmp.second] = true;
               }
           }
       }
       
       int res = 0;
       int cnt = 0;
       for (bool tmp : isValid) {
           if (tmp) {
               cnt++;
               res = max(res, cnt);
           } else {
               cnt = 0;
           }
       }
       return res;
    }

    // A better one, it runs 12ms.
    int longestValidParentheses(string s) {
        int len = (int)s.length();
        stack<int> sta;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else if (!sta.empty()) {
                if (s[sta.top()] == '(') {
                    sta.pop();
                } else {
                    sta.push(i);
                }
            } else {
                sta.push(i);
            }
        }
        
        if (sta.empty()) {
            return len;
        } else {
            int res = 0;
            int l = 0, r = len - 1;
            while (!sta.empty()) {
                l = sta.top();
                sta.pop();
                res = max(res, r - l);
                r = l - 1;
            }
            return max(res, l);
        }
    }

    // DP solutoin. It runs 8ms.
    int longestValidParentheses(string s) {
        int len = (int)s.length();
        vector<int> dp(len, 0);
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i > 1 ? (dp[i - 2] + 2) : 2;
                    res = max(res, dp[i]);
                } else {
                    if ((i - dp[i - 1] - 1 >= 0) && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0) {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                        res = max(res, dp[i]);
                    }
                }
            }
        }
        return res;
    }
};