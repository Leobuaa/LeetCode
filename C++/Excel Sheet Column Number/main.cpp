class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int len = s.length();
        for (int i = len; i > 0; i--)
            res += (s[i - 1] - 'A' + 1) * pow(26, (len - i));
        return res;
    }
};