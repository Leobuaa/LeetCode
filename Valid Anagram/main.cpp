class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int alp[26] = {0};
        for (int i = 0; i < s.length(); i++)
            alp[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++)
            alp[t[i] - 'a']--;
        for (int i = 0; i < 26; i++)
        {
            if (alp[i] != 0)
                return false;
        }
        return true;
    }
};