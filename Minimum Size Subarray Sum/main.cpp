class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
        int l = 1, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            bool flag = false;
            for (int i = 0; i <= nums.size() - mid; i++) {
                if (dp[mid + i] - dp[i] >= s) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i <= nums.size() - l; i++) {
            if (dp[l + i] - dp[i] >= s) {
                res = l;
                break;
            }
        }
        return res;
    }
};