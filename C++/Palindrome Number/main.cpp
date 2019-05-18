class Solution {
public:
	// It runs 84 ms.
    bool isPalindrome(int x) {
        int r = 0;
        if((x % 10 == 0 && x != 0) || x < 0) return false;
        while (r < x) {
            r = 10 * r + x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }

    // It runs 72 ms.
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        int div = 1;
        while (x / div >= 10)
            div *= 10;
        while (x > 0)
        {
            int l = x / div;
            int r = x % 10;
            if (l != r) return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
};