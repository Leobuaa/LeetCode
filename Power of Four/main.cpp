class Solution {
public:
	// Recursive
    bool isPowerOfFour(int num) {
        return (num == 1) || (num > 1 && num % 4 == 0 && isPowerOfFour(num / 4));
    }

    // Without rescursive or loop
    bool isPowerOfFour(int num) {
        return (num == 1) || (num > 1 && (num&-num)==num) && (num & 0x2aaaaaab) == 0;
    }
};