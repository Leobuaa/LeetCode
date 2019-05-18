class Solution {
public:
	// It runs 8ms. A very good solutions from discuss.
    bool isIsomorphic(string s, string t) {
        int a1[256] = {0}, a2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (a1[s[i]] != a2[t[i]])   return false;
            a1[s[i]] = i + 1;
            a2[t[i]] = i + 1;
        }
        return true;
    }
};