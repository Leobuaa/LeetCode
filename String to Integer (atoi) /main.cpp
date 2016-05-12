class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int res = 0, i = 0;
        bool flag, overflow = false;
        i = str.find_first_not_of(' ');
        if (str[i] == '-' || str[i] == '+')
            flag = str[i++] == '-' ? true : false;
        while (isdigit(str[i])) {
            int temp = res * 10 + (str[i++] - '0');
            if (temp / 10 != res)
            {
                overflow = true;
                break;
            }
            res = temp;
         }
         if (overflow)   return flag ? INT32_MIN : INT32_MAX;
         return flag ? -res : res;
    }
};