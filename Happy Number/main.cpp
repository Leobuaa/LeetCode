class Solution {
public:
    // My solution
    int tran(int n) 
    {
        int res = 0;
        while (n > 0)
        {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        if (n <= 0) return false;
        vector<bool> rep(1000, false);
        
        n = tran(n);
        
        while (! rep[n])
        {
            rep[n] = true;
            if (n == 1) return true;
            n = tran(n);
        } 
        
        return false;
    }
};