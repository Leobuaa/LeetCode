class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0;
        string temp = t;
        for (char c : s) {
            pos = temp.find_first_of(c);
            if (pos == -1) {
                return false;
            }
            temp = temp.substr(pos + 1);
        }
        return true;
    }
};