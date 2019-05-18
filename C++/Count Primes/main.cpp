class Solution {
public:
    // Not a very good solution, it runs 134ms.
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        
        int res = 1;
        vector<bool> primes(n + 1, true);
        for (long long i = 3; i < n; i += 2) {
            if (primes[i]) {
                res++;
                for (long long j = i * i; j < n; j += (2 * i)) {
                    primes[j] = false;
                }
            }
        }
        
        return res;
    }

    // this method run 28ms, the key is not to change 'n' to 'upper', when use bool* , it is much faster.
    // when I use 'n', not 'upper', it runs 36ms.
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        
        bool* primes = new bool[n];
        int upper = sqrt(n);
        for (int i = 3; i <= upper; i += 2) {
            if (!primes[i]) {
                if (i > upper) {
                    continue;
                }
                for (int j = i * i, k = i << 1; j < n; j += k) {
                    primes[j] = true;
                }
            }
        }
        
        int res = 1;
        for (int i = 3; i < n; i += 2) {
            if (!primes[i]) {
                res++;
            }
        }
        
        return res;
    }

};