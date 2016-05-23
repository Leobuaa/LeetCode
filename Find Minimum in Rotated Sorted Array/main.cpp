class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        int res = nums[0];
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                res = nums[mid];
                break;
            }
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};