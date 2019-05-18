class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) {
            return N;
        }
        int bit = 1;
        int copyN = N;
        while (copyN > 0) {
            int x = copyN % 10;
            copyN /= 10;
            int y = copyN % 10;
            if (y <= x) {
                bit++;
                continue;
            }
            return monotoneIncreasingDigits(copyN - 1) * pow(10, bit) + pow(10, bit) - 1;
        }
        return N;
    }
};