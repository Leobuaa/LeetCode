class Solution {
public:
    // My solution, it runs 28ms.
    int lengthOfLongestSubstring(string s) {
        int len = (int)s.length();
        if (len <= 0) {
            return 0;
        }
        vector<int> map(260, -1);
        int res = 0;
        int index = 0;
        for (int i = 0; i < len; i++) {
            index = max(index, map[s[i]] + 1);
            map[s[i]] = i;
            res = max(res, i - index + 1);
        }
        return res;
    }

    // It runs 16ms.
    int lengthOfLongestSubstring(string s) {
        int len = (int)s.length();
        if (len <= 0) {
            return 0;
        }
        vector<int> map(260, -1);
        int res = 0;
        int index = 0;
        for (int i = 0; i < len; i++) {
            if (map[s[i]] >= index) {
                res = max(res, i - index);
                index = map[s[i]] + 1;
            }
            map[s[i]] = i;
        }
        return max(res, len - index);
    }
};