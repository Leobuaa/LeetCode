class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = (l + r) >> 1;
        while (l < r) {
            if (nums[mid] == target) {
                break;
            }
            
            if (nums[mid] > nums[r]) {
                if (nums[mid] > target && nums[l] <= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[r]) {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                r--;
            }
            
            mid = (l + r) >> 1;
        }
        
        return nums[mid] == target ? true : false;
    }
};