class Solution {
public:
    // A brilliant solution from discuss 
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for (auto c : t) {
            map[c]++;
        }
        int counter = t.length(), begin = 0, end = 0, len = INT32_MAX, head = 0;
        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            
            while (counter == 0) {
                if (end - begin < len) {
                    len = end - begin;
                    head = begin;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }
        }
        
        return len == INT32_MAX ? "" : s.substr(head, len);
    }
};