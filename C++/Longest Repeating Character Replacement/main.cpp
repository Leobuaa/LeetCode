class Solution {
public:
    // LeetCode discuss solution. It runs 36ms.
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, alp[91] = {};
        while (j < s.length()) {
            alp[s[j++]]++;
            if ((j - i - *max_element(alp + 65, alp + 91)) > k) {
                alp[s[i++]]--;
            }
        }
        return j - i;
    }
};