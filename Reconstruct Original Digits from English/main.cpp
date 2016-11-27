class Solution {
public:
    // My first solution
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

    // More space, it runs faster.
    string originalDigits(string s) {
        vector<int> alp(128, 0);
        for (char c : s) {
            alp[c]++;
        }
        
        vector<int> res(10, 0);
        res[0] = alp['z'];
        res[2] = alp['w'];
        res[4] = alp['u'];
        res[1] = alp['o'] - (res[0] + res[2] + res[4]);
        res[6] = alp['x'];
        res[7] = alp['s'] - res[6];
        res[5] = alp['v'] - res[7];
        res[8] = alp['g'];
        res[3] = alp['h'] - res[8];
        res[9] = alp['i'] - (res[5] + res[6] + res[8]);
        
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