class Solution {
public:
    void reverseWords(string &s) {
        int len = (int)s.length();
        int pos1 = 0, pos2 = 0;
        while (true) {
            while (pos1 < len - 1 && s[pos1] == ' ') {
                pos1++;
            }
            pos2 = pos1;
            while (pos2 < len && s[pos2] != ' ') {
                pos2++;
            }
            int mid = (pos1 + pos2) / 2;
            for (int i = pos1; i < mid; i++) {
                swap(s[i], s[pos2 + pos1 - i - 1]);
            }
            
            if (pos2 >= len - 1) {
                break;
            }
            pos1 = pos2 + 1;
            if (pos1 >= len - 1) {
                break;
            }
        }
        
        pos1 = 0, pos2 = len - 1;
        int mid = (pos1 + pos2) / 2;
        while (pos1 <= mid) {
            swap(s[pos1++], s[pos2--]);
        }
        
        while (s[0] == ' ') {
            s.erase(0, 1);
        }
        while (s[s.length() - 1] == ' ') {
            s.erase(s.length() - 1, 1);
        }
        
        for (int i = 1; i < s.length();) {
            if (s[i - 1] == ' ' && s[i] == ' ') {
                s.erase(i, 1);
            } else {
                i++;
            }
        }
    }
};