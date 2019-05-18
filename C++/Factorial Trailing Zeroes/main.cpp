class Solution {
public:
	// It is a math problem.
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0)
            res += n = n/5;
        return res;
    }
};