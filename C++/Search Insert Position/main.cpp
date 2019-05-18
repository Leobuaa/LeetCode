class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())   return 0;
        int l = 0, r = nums.size() - 1, mid = l + (r - l) / 2;
        while (l <= r)
        {
            if (target <= nums[l])  return l;
            if (target > nums[r])  return r + 1;
            if (target == nums[r])  return r;
            if (target == nums[mid])    return mid;
            if (target < nums[mid]) 
                r = mid;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }
    }
};