class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alp(26, 0);
        for (char c : s) {
            alp[c - 'a']++;
        }
        
        int res = -1;
        for (int i = 0; i < s.length(); i++) {
            if (alp[s[i] - 'a'] == 1) {
                res = i;
                break;
            }
        }
        
        return res;
    }
};