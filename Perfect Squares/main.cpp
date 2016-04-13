class Solution {
public:
    /**
     * Use dynamic programming and static value. It runs 12 ms
     * Without using static, it runs 436ms
     * @param  n [description]
     * @return   [description]
     */
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        static vector<int> dp(1, 0);
        
        while (dp.size() <= n) {
            int size = dp.size();
            int temp = INT32_MAX;
            for (int j = 1; j * j <= size; j++) {
                temp = min(temp, dp[size - j * j] + 1);
            }
            dp.push_back(temp);
        }
        return dp[n];
    }
};