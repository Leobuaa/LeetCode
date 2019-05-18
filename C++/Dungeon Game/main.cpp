class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = 0;
        if (m > 0) {
            n = dungeon[0].size();
        }
        
        if (m == 0 || n == 0) {
            return 1;
        }
        
        vector<vector<int>> minHP(m + 1, vector<int>(n + 1, INT32_MAX));
        minHP[m - 1][n] = minHP[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int temp = min(minHP[i + 1][j], minHP[i][j + 1]) - dungeon[i][j];
                minHP[i][j] = temp <= 0 ? 1 : temp;
            }
        }
        return minHP[0][0];
    }
};