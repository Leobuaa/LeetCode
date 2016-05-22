class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        if (x < 0) {
            return INT32_MIN;
        }
        
        int l = 1, r = 46340;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid * mid == x) {
                return mid;
            }
            
            if (mid * mid < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return r * r > x ? r - 1 : r;
    }
};