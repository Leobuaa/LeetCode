class Solution {
public:
    // Math problem.
    int integerBreak(int n) {
        if (n <= 3) {
            return n == 2 ? 1 : 2;
        }
        
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        
        res *= n;
        return res;
    }
};