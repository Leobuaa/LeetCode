class Solution {
public:
	// This is not the good solution. It runs 26ms.
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int res = 0;
        for (int n : nums) {
            res += abs(n - mid);
        }
        return res;
    }

    // Another solution. It runs 16ms.
    int minMoves2(vector<int>& nums) {
        int res = 0;
        int size = nums.size();
        auto it = nums.begin() + size / 2;
        nth_element(nums.begin(), it, nums.end());
        int mid = *it;
        for (int n : nums) {
            res += abs(mid - n);
        }
        return res;
    }
};