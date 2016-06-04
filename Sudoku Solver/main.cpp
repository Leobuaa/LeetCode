class Solution {
public:
    // Backtracking. Use a vector to store the solution.
    void solveSudoku(vector<vector<char>>& board) {
        const int n = 9;
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> cube(9, vector<bool>(10, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isdigit(board[i][j])) {
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    cube[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
                }
            }
        }
        
        int i = 0, j = 0;
        vector<vector<int>> sta;
        
        while (i < n && j < n) {
            
            if (isdigit(board[i][j])) {
                if (j < n - 1) {
                    j++;
                } else {
                    i++;
                    j = 0;
                }
                continue;
            }
            
            bool flag = false;
            for (int c = 1; c <= n; c++) {
                if (!row[i][c] && !col[j][c] && !cube[i / 3 * 3 + j / 3][c]) {
                    board[i][j] = c + '0';
                    row[i][c] = col[j][c] = cube[i / 3 * 3 + j / 3][c] = true;
                    flag = true;
                    vector<int> tmp = {i, j, c};
                    sta.push_back(tmp);
                    break;
                }
            }
            
            if (!flag) {
                while (!flag && !sta.empty()) {
                    vector<int> top = sta.back();
                    sta.pop_back();
                    int topI = top[0], topJ = top[1], topC = top[2];
                    row[topI][topC] = col[topJ][topC] = cube[topI / 3 * 3 + topJ / 3][topC] = false;
                    board[topI][topJ] = '.';
                    for (int c = topC + 1; c <= n; c++) {
                        if (!row[topI][c] && !col[topJ][c] && !cube[topI / 3 * 3 + topJ / 3][c]) {
                            board[topI][topJ] = c + '0';
                            row[topI][c] = col[topJ][c] = cube[topI / 3 * 3 + topJ / 3][c] = true;
                            vector<int> tmp = {topI, topJ, c};
                            sta.push_back(tmp);
                            i = topI;
                            j = topJ;
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }

    }
};