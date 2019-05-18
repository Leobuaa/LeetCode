class Solution {
    public:
        int integerReplacement(int n) {
            if (n == 1) {
                return 0;
            }

            if (n == INT32_MAX) {
                return 32;
            }

            return (n % 2 ? min(integerReplacement(n + 1), integerReplacement(n - 1)) : integerReplacement(n / 2)) + 1;
        }
};
