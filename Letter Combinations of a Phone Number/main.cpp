class Solution {
public:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        int len = (int)digits.length();
        vector<string> res;
        if (len == 0) {
            return res;
        }
        res.push_back("");
        for (int i = 0; i < len; i++) {
            int size = (int)res.size();
            for (int j = 0; j < size; j++) {
                int mapLen = map[digits[i] - '0'].length();
                for (int k = 0; k < mapLen; k++) {
                    res.push_back(res[j] + map[digits[i] - '0'][k]);
                }
            }
            res.erase(res.begin(), res.begin() + size);
        }
        return res;
    }
};