class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        unsigned long long cnt;
        if (n < 0) {
            cnt = -n;
            x = 1 / x;
        } else {
            cnt = n;
        }
        while (cnt > 0) {
            if (cnt & 1) {
                res *= x;
            }
            x *= x;
            cnt >>= 1;
        }
        
        return res;
    }
};