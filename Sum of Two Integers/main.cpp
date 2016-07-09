class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        return getSum((a&b)<<1, a^b);
    }

    int getSum(int a, int b) {
        int sum = a | b, c = a & b;
        while (c != 0) {
            a = sum ^ c;
            b = c << 1;
            sum = a | b;
            c = a & b;
        }
        return sum;
    }
};