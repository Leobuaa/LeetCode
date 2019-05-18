class Solution {
public:
    // binary search O(n*lg(m))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, n = matrix.size(), m = 0;
        if (n > 0) {
            m = matrix[0].size();
        }
        
        if (m == 0 || n == 0) {
            return false;
        }
        
        while (row < n) {
            if (matrix[row][0] > target) {
                break;
            }
            
            if (matrix[row][m - 1] < target) {
                row++;
                continue;
            }
            
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (target == matrix[row][mid]) {
                    return true;
                }
                
                if (target > matrix[row][mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            row++;
        }
        
        return false;
    }

    // O(m + n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = 0;
        if (matrix.size() > 0) {
            c = matrix[0].size() - 1;   
        }
        
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            
            if (matrix[r][c] > target) {
                c--;
            } else {
                r++;
            }
        }
        
        return false;
    }
};