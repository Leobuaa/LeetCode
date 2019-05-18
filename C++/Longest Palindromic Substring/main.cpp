class Solution {
public:
    string longestPalindrome(string s) {
        int len = (int)s.length();
        if (len < 2) {
            return s;
        }
        string res = "";
        int maxLen = 1;
        int maxLeft = 0;
        for (int i = 0; i < len && len - i > maxLen / 2;) {
            int left, right;
            left = right = i;
            while (right < len - 1 && s[right] == s[right + 1]) {
                right++;
            }
            i = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                left--;
                right++;
            }
            
            if (right - left + 1 > maxLen) {
                maxLeft = left;
                maxLen = right - left + 1;
            }
        }
        
        res = s.substr(maxLeft, maxLen);
        return res;
    }
};