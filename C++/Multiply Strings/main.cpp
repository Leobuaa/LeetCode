class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = int(num1.length()), len2 = int(num2.length());
        string res(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; i--)
        {
            int addFlag = 0;
            for (int j = len2 - 1; j >= 0; j--)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0');
                temp += (addFlag + int(res[i + j + 1] - '0'));
                addFlag = temp / 10;
                res[i + j + 1] = char((temp % 10 + '0'));
            }
            res[i] = char(res[i] + addFlag);
          }

        auto pos = res.find_first_not_of('0');
        if (pos != -1)
            return res.substr(pos);
        else
            return "0";
    }
};