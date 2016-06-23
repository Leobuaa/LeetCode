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

    // Use constant space solution
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = 0;
        if (row > 0) {
            col = matrix[0].size();
        }
        
        int cols = 1;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                cols = 0;
            }
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (cols == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};