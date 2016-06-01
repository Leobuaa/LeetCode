class Solution {
public:
    // The solution use hash table and two pointers.
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.length()  <= 0 || words.size() <= 0) {
            return res;
        }
        
        int wordLen = words[0].length();
        int cnt = words.size();
        int length = s.length();
        
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            map[words[i]]++;
        }
        
        for (int i = 0; i < wordLen; i++) {
            int start = i, count = 0;
            unordered_map<string, int> tmp;
            for (int j = i; j <= length - wordLen; j += wordLen) {
                string s1 = s.substr(j, wordLen);
                if (map.find(s1) != map.end()) {
                    tmp[s1]++;
                    if (tmp[s1] <= map[s1]) {
                        count++;
                    } else {
                        while (tmp[s1] > map[s1]) {
                            string s2 = s.substr(start, wordLen);
                            tmp[s2]--;
                            if (tmp[s2] < map[s2]) {
                                count--;
                            }
                            start += wordLen;
                        }
                    }
                    
                    if (count == cnt) {
                        res.push_back(start);
                    }
                    
                } else {
                    tmp.clear();
                    count = 0;
                    start = j + wordLen;
                }
            }
        }
        return res;
    }
};