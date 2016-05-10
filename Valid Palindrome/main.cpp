class Solution {
public:
    bool isPalindrome(string s) {
        int len = int (s.length());
        int i = 0, j = len - 1;
        while (i <= j)
        {
            while (i < j && !isalpha(s[i]) && !isdigit(s[i]))
                i++;
            while (i < j && !isalpha(s[j]) && !isdigit(s[j]))
                j--;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};