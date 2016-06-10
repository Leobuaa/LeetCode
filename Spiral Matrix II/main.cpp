class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int row = n - 1, col = n - 1;
        for (int i = 0; i < (n + 1) >> 1; i++) {
            for (int j = i; j <= col; j++) {
                res[i][j] = num++;
            }
            
            for (int j = i + 1; j <= row; j++) {
                res[j][col] = num++;
            }
            
            for (int j = col - 1; j >= i; j--) {
                res[row][j] = num++;
            }
            
            for (int j = row - 1; j > i; j--) {
                res[j][i] = num++;
            }
            row--;
            col--;
        }
        return res;
    }
};