class Solution {
public:
    int row, col;

    bool isAlive(vector<vector<int>>& board, int i, int j) {
        bool alive = (board[i][j] & 1 ? true : false);
        int cnt = 0;
        if (i > 0) {
            cnt += board[i - 1][j] & 1;
            if (j > 0) {
                cnt += board[i - 1][j - 1] & 1;
            }
            if (j < col - 1) {
                cnt += board[i - 1][j + 1] & 1;
            }
        }
        
        if (i < row - 1) {
            cnt += board[i + 1][j] & 1;
            if (j > 0) {
                cnt += board[i + 1][j - 1] & 1;
            }
            if (j < col - 1) {
                cnt += board[i + 1][j + 1] & 1;
            }
        }
        
        if (j > 0) {
            cnt += board[i][j - 1] & 1;
        }
        
        if (j < col - 1) {
            cnt += board[i][j + 1] & 1;
        }
        
        bool res = false;
        if (alive && (cnt == 2 || cnt == 3)) {
            res = true;
        }
        
        if (!alive && cnt == 3) {
            res = true;
        }
        
        return res;
    }

    void gameOfLife(vector<vector<int>>& board) {
        row = board.size();
        if (row > 0) {
            col = board[0].size();
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isAlive(board, i, j)) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                   board[i][j] >>= 1;
            }
        }
    }
};