class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int length = 0, N = A.size();
        
        if (N <= 2) {
            return 0;
        }
        
        int diff = A[1] - A[0];
        
        for (int i = 2; i < N; i++) {
            int temp = A[i] - A[i - 1];
            
            if (diff == temp) {
                length++;
            } else if (length > 0) {
                res += (((length + 1) * length) / 2);
                length = 0;
            }
            
            diff = temp;
        }
        
        res += (((length + 1) * length) / 2);
        
        return res;
    }
};