class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        bool res[sum + 1] = {false};
        res[0] = true;
        for (int num : nums) {
            for (int i = sum; i >= 0; i--) {
                if (res[i]) {
                    res[i + num] = true;
                }
            }
            if (res[sum / 2]) {
                return true;
            }
        }
        
        return false;
    }
};