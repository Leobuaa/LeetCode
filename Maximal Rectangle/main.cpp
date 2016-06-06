class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        const int row = matrix.size();
        const int col = matrix[0].size();
        
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        
        int res = 0;
        for (int i = 0; i < row; i++) {
            int curLeft = 0, curRight = col;
            
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = col;
                    curRight = j;
                }
            }
            
            for (int j = 0; j < col; j++) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        
        return res;
    }
};