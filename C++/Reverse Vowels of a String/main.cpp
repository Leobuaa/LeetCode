class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};