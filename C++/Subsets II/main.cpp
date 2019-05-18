class Solution {
public:
    void subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int start) {
        res.push_back(subset);
        int i = start;
        while (i < nums.size()) {
            subset.push_back(nums[i]);
            subsets(nums, res, subset, i + 1);
            subset.pop_back();
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        subsets(nums, res, subset, 0);
        return res;
    }
};