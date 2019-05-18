class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if (n <= 0) {
            return 0;
        }
        
        vector<long long> dp(n, 0);
        long long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
        }
        
        for (int i = 0; i < n; i++) {
            dp[0] += i * A[i];
        }
        
        res = dp[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + sum - n * A[n - i];
            res = max(res, dp[i]);
        }
        
        return (int)res;
    } 
};