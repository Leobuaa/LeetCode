// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int res = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1); // The key point, it will overflow if use (low + high) >> 1;
            int ges = guess(mid);
            if (ges == 0) {
                res = mid;
                break;
            } else if (ges > 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return res;
    }
};