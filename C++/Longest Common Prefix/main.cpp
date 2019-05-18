class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty())   return res;
        res = strs[0];
        int size = int(strs.size());
        for (int i = 1; i < size; i++)
        {
            int len1 = int(res.length()), len2 = int(strs[i].length());
            int minLen = min(len1, len2);
            int j = 0;
            for (j = 0; j < minLen; j++)
                if (res[j] != strs[i][j])   break;
            res.erase(res.begin() + j, res.end());
        }
        return res;
    }
};