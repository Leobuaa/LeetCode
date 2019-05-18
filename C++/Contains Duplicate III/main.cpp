class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> range;
        int len = int(nums.size());
        for (int i = 0; i < len; i++)
        {
            if (i > k)  range.erase(nums[i - k - 1]);
            auto p = range.lower_bound(nums[i] - t);
            if (p != range.end() && *p - nums[i] <= t)  return true;
            range.insert(nums[i]);
        }
        return false;
    }
};