class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n > 0)
        {
            string num = res;
            int len = int(num.length());
            res.clear();
            int pos = 0, count = 0;
            while (pos < len)
            {
                count++;
                pos++;
                if (pos == len || num[pos] != num[pos - 1])
                {
                    res += to_string(count) + num[pos - 1];
                    count = 0;
                }
            }
        }
        return res;
    }
};