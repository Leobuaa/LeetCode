class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = 0;;
        if (row > 0) {
            column = matrix[0].size();
        }
        
        if (row == 0 || column == 0) {
            return false;
        }
        
        int l = 0, r = row * column - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / column][mid % column] == target) {
               return true;
            }
            
            if (matrix[mid / column][mid % column] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return false;
    }
};