class Solution {
public:
    // My solution
    string originalDigits(string s) {
        vector<int> alp(26, 0);
        for (char c : s) {
            alp[c - 'a']++;
        }
        
        vector<int> res(10, 0);
        res[0] = alp['z' - 'a'];
        res[2] = alp['w' - 'a'];
        res[4] = alp['u' - 'a'];
        res[1] = alp['o' - 'a'] - (res[0] + res[2] + res[4]);
        res[6] = alp['x' - 'a'];
        res[7] = alp['s' - 'a'] - res[6];
        res[5] = alp['v' - 'a'] - res[7];
        res[8] = alp['g' - 'a'];
        res[3] = alp['h' - 'a'] - res[8];
        res[9] = alp['i' - 'a'] - (res[5] + res[6] + res[8]);
        
        string resString;
        for (int i = 0; i < 10; i++) {
            if (res[i] > 0) {
                string tmp(res[i], i + '0');
                resString += tmp;
            }
        }
        
        return resString;
    }
};