class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1') {
            grid[i][j] = '0';
        } else {
            return;
        }
        DFS(grid, i - 1, j);
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i + 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row > 0) {
            col = grid[0].size();
        }
        
        if (row == 0 || col == 0) {
            return 0;
        }
        
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
    
    int row;
    int col;
};