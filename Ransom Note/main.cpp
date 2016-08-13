class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dic1(256, 0);
        vector<int> dic2(256, 0);
        
        for (char c : magazine) {
            dic1[c]++;
        }
        
        for (char c : ransomNote) {
            dic2[c]++;
            if (dic2[c] > dic1[c]) {
                return false;
            }
        }
        
        return true;
    }
};