class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alp(26, 0);
        for (char c : s) {
            alp[c - 'a']++;
        }
        
        for (char c : t) {
            alp[c - 'a']--;
        }
        
        char res;
        
        for (int i = 0 ; i < 26; i++) {
            if (alp[i]) {
                res = i + 'a';
            }
        }
        
        return res;
    }
};