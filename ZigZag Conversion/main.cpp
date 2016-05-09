class Solution {
public:
    string convert(string s, int numRows) {
        int pos = 0, row = 0, len = s.length();
        if (numRows == 1 || len <= 0)   return s;
        vector<string> res(numRows, "");
        int flag = 1;
        res[row++].push_back(s[pos++]);
        while (pos < len)
        {
            res[row].push_back(s[pos++]);
            if (row == numRows - 1 || row == 0) flag = -flag;
            row += flag;
        }
        string str = "";
        for (int i = 0; i < numRows; i++)
            str += res[i];
        return str;
    }
};