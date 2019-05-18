class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x)
        {
            // Handle the case of overflow
            if (INT32_MAX / 10 < res || INT32_MIN / 10 > res) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};