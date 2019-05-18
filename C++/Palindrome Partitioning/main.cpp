class Solution {
public:
    vector<vector<string>> partition(string s, int n) {
        if (n == 1) {
            return vector<vector<string>> {{{s[0]}}};
        }
        
        string str = {s[n - 1]};
        vector<vector<string>> res = partition(s, n - 1);
        int m = res.size();
        for (int i = 0; i < m; i++) {
            int l = res[i].size();
            if (l > 0 && res[i][l - 1] == str) {
                vector<string> tmp = res[i];
                tmp[l - 1] += str;
                res.push_back(tmp);
            }
            
            if (l > 1 && res[i][l - 2] == str) {
                vector<string> tmp(res[i].begin(), res[i].end() - 1);
                tmp[l - 2] += res[i][l - 1] + str;
                res.push_back(tmp);
            }
            
            res[i].push_back(str);
        }
        
        return res;
    }

    vector<vector<string>> partition(string s) {
        return partition(s, s.length());
    }
};