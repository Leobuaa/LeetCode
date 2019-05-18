class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alp(256, 0);
        for (char c : s) {
            alp[c]++;
        }
        
        int res = 0;
        for (int i = 0; i < 256; i++) {
            res += alp[i];
            if (alp[i] & 1) {
                res -= 1;
                res |= 1;
            }
        }
        
        return res;
    }
};