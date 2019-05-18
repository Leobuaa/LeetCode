class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1) {
            return s.length();
        }
        int res = 0;
        return helper(s, k, 0, s.length() - 1);
    }
    
    int helper(string s, int k, int l, int r) {
        if (r - l + 1 < k) {
            return 0;
        }
        
        int alp[26] = {0};
        for (int i = l; i <= r; i++) {
            alp[s[i] - 'a']++;
        }
        
        int res = 0;
        int start = l;
        bool flag = true;
        for (int i = l; i <= r; i++) {
            if (alp[s[i] - 'a'] < k) {
                res = max(res, helper(s, k, start, i - 1));
                start = i + 1;
                flag = false;
            }
        }
        
        if (flag) {
            return r - l + 1;
        }
        
        return max(res, helper(s, k, start, r));
    }

};