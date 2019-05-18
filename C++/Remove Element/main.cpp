class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = (int)nums.size();
        int l = 0, r = len - 1;
        int cnt = 0;
        while (l <= r) {
            while (l <= r && nums[l] != val) {
                l++;
            }
            if (l <= r) {
                cnt++;
                swap(nums[l], nums[r--]);
            }
        }
        nums.erase(nums.begin() + r + 1, nums.end());
        return len - cnt;
    }
};