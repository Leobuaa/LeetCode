class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] <= nums[i - 1]) {
                continue;
            }
            reverse(nums.begin() + i, nums.end());
            auto pos = upper_bound(nums.begin() + i, nums.end(), nums[i - 1]);
            swap(*pos, nums[i - 1]);
            return;
        }
        reverse(nums.begin(), nums.end());
    }
};