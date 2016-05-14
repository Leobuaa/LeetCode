class Solution {
public:
    // O(nlgn), it runs 4ms.
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return res.size();
    }

    // DP, O(n^2), it runs 104ms.
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j] + 1);
                }
            }
            dp[i] = tmp;
            res = max(dp[i], res);
        }
        return res;
    }
};