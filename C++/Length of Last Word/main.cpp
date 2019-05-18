class Solution {
public:
    int lengthOfLastWord(string s) {
        string s1 = s.substr(0, s.find_last_not_of(' ') + 1);
        auto pos = s1.find_last_of(' ');
        if (pos == -1)  return s1.length();
        
        return (s1.substr(pos + 1)).length();
    }
};