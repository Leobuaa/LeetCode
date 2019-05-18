class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if (!len2)  return 0;
        for (int i = 0; i < len1 - len2 + 1; i++)
        {
            bool flag = true;
            for (int j = 0; j < len2; j++)
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            if (flag)   return i;
        }
        return -1;
    }
};