class Solution {
public:
    int romanMap(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int len = s.length();
        int res = romanMap(s.back());
        for (int i = len - 2; i >= 0; i--)
        {
            if (romanMap(s[i]) >= romanMap(s[i + 1]))
                res += romanMap(s[i]);
            else
                res -= romanMap(s[i]);
        }
        return res;
    }
};