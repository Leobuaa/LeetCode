class Solution {
    public:
        int findNthDigit(int n) {

            if (n <= 9) {
                return n;
            }

            long long mask = 9, count = 1;
            while (n > mask * count) {
                n -= mask * count;
                mask *= 10;
                count++;
            }


            int num = (n / count) + pow(10, count - 1) - 1;
            int res = 0;

            res = ((n % count == 0) ? num : (num + 1) / pow(10, count - (n % count)));
            res %= 10;

            return res;

        }
};
