class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = num;
        long long mid;
        while (l < r) {
            mid = (l + r) >> 1;
            long long temp = mid * mid;
            if (temp == num) {
                return true;
            }
            if (temp > num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l * l == num;
    }
};