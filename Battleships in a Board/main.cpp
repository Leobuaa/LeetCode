class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int width = board.size(), height = 0;
        if (width > 0) {
            height = board[0].size();
        }
        
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (board[i][j] == 'X') {
                    if ((i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) {
                        
                    } else {
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
};