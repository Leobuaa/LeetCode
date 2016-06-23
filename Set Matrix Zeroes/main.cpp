class Solution {
public:
    // Use O(m+n) space, not the best solution.
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = 0;
        if (row > 0) {
            col = matrix[0].size();
        }
        
        vector<bool> rowFlag(row, false);
        vector<bool> colFlag(col, false);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rowFlag[i] = colFlag[j] = true;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (rowFlag[i]) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (colFlag[j]) {
                for (int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};