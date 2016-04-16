class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        int mask = 1;
        while (n > 0)
        {
            int mod = --n % 26;
            res = char(mod + 'A') + res;
            n /= 26;
        }
        return res;
    }
};