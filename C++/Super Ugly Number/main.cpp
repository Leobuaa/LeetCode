class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (primes.empty()) {
            return 0;
        }
        int size = primes.size();
        vector<int> dp1(size, 0);
        vector<int> dp2 = {1};
        
        int cnt = n;
        while (--cnt) {
            int minVal = INT32_MAX;
            for (int i = 0; i < size; i++) {
                minVal = min(primes[i] * dp2[dp1[i]], minVal);
            }
            
            for (int i = 0; i < size; i++) {
                if (minVal % primes[i] == 0) {
                    dp1[i]++;
                }
            }
            
            dp2.push_back(minVal);
        }
        
        return dp2[n - 1];
    }
};