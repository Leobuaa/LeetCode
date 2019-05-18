class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            
            if (nums[mid] == nums[r]) {
                r--;
                continue;
            }
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]){
                r = mid;
            }
        }
        return nums[l];
    }
};