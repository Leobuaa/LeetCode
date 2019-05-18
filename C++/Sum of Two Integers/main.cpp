class Solution {
public:
	// Recursive
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        return getSum((a&b)<<1, a^b);
    }

    // Iterative 
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

    // Iterative 
    int getSum(int a, int b) {
        int sum = 0;
        do {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }while (b != 0);
        return sum;
    }
};