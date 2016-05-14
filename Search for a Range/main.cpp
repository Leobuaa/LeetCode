class Solution {
public:
    // Use STL
    vector<int> searchRange(vector<int>& nums, int target) {
        auto pos1 = lower_bound(nums.begin(), nums.end(), target);
        auto pos2 = upper_bound(nums.begin(), nums.end(), target);
        
        vector<int> res(2, -1);
        if (pos1 != nums.end() && *pos1 == target) {
            res[0] = pos1 - nums.begin();
            res[1] = pos2 - nums.begin() - 1;
        }
        
        return res;
    }

    // Do not use STL
    int firstGreater(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = (l + r) >> 1;
        while (l < r) {
            if (nums[mid] <=  target) {
                l = mid + 1;
            } else {
                r = mid;
            }
            mid = (l + r) >> 1;
        }
        
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int pos1 = firstGreater(nums, target - 1);
        int pos2 = firstGreater(nums, target);
        
        vector<int> res(2, -1);
        
        if (nums[pos1] == target) {
            res[0] = pos1;
            res[1] = nums[pos2] > target ? pos2 - 1: pos2;
        }
        
        return res;
    }
};