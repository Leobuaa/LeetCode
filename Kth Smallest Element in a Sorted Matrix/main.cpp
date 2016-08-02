class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = (l + r) >> 1;
            int num = 0;
            for (int i = 0; i < n; i++) {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            
            if (num < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};