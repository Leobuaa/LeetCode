class Solution {
public:
	// The math problem
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }

    int bulbSwitch(int n) {
        if (n <= 1) return n;
        int res = 0;
        int mask = 1, count = 1;
        while (mask <= n)
        {
            res++;
            count++;
            mask = count * count;
        }
        return res;
    }
};