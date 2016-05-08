class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int pos1 = a.length() - 1, pos2 = b.length() - 1, count = 0;
        while (pos1 >= 0 || pos2 >= 0 || count)
        {
            count += pos1 >= 0 ? a[pos1--] - '0' : 0;
            count += pos2 >= 0 ? b[pos2--] - '0' : 0;
            res = to_string(count % 2) + res;
            count /= 2;
        }
        return res;
    }
};