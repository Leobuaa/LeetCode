class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.length() <= 0) {
            return 0;
        }
        int res = 0, cnt = 1;
        int alp[26] = {0};
        alp[p[0] - 'a'] = 1;
        for (int i = 1; i < p.length(); i++) {
            if (isNext(p[i - 1], p[i])) {
                alp[p[i] - 'a'] = max(alp[p[i] - 'a'], ++cnt);
            } else {
                cnt = 1;
                alp[p[i] - 'a'] = max(alp[p[i] - 'a'], 1);
            }
        }
        for (int cnt : alp) {
            res += cnt;
        }
        return res;
    }
    
    bool isNext(const char& x,const char& y) {
        return y - x == 1 || x - y == 25;
    }
};