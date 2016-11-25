class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int res = 0;
        for (int n : nums) {
            res += abs(n - mid);
        }
        return res;
    }
};