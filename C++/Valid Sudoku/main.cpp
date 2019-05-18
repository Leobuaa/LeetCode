class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> check1(9, vector<bool>(9,false)), 
                             check2(9, vector<bool>(9,false)), 
                             check3(9, vector<bool>(9,false));
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (isdigit(board[i][j]))
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (check1[i][num] || check2[j][num] || check3[k][num]) return false;
                    check1[i][num] = check2[j][num] = check3[k][num] = true;
                }
            }
        }
         
        return true;
    }
};