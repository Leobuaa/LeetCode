class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        if (size > 0)   dp.push_back(nums[0]);
        for (int i = 1; i < size; i++)
            dp.push_back(dp[i - 1] + nums[i]);
    }

    int sumRange(int i, int j) {
        if (i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};