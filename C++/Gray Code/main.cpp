class Solution {
public:
    // Recursive
    void grayCode(int n, vector<int>& res)
    {
        if (n == 0) return;
        grayCode(n - 1, res);
        int mask = 1 << (n - 1);
        int posR = mask, posL = mask;
        while (posL--)
        {
            res[posR++] = mask | res[posL];
        }
    }
    
    vector<int> grayCode(int n) {
        if (n <= 0)
            return vector<int>(1, 0);
        int size = 1 << n;
        vector<int> res(size, 0);
        res[1] = 1;
        grayCode(n, res);
        return res;
    }
};