class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        int len = s.length();
        for (int i = 0; i <= len - 10; i++) {
            string s1 = s.substr(i, 10);
            map[s1]++;
        }
        
        for (auto str : map) {
            if (str.second > 1) {
                res.push_back(str.first);
            }
        }
        return res;
    }

    // A better solution from discuss. ACGT in ACSCII can be recognized in the last three bits.
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> map;
        vector<string> res;
        int key = 0, i = 0, len = s.length();
        while (i < 9) {
            key = key << 3 | s[i++] & 7;
        }
        
        while (i < len) {
            if (map[key = (key << 3) & 0x3FFFFFFF | s[i++] & 7 ]++ == 1) {
                res.push_back(s.substr(i - 10, 10));
            }
        }
        
        return res;
    }
};