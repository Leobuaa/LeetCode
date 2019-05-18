class Solution {
public:
    // Backtracking
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        subsets(nums, sub, res, 0);
        return res;
    }
    
    void subsets(vector<int>& nums, vector<int>& sub, vector<vector<int>>& subs, int start) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subsets(nums, sub, subs, i + 1);
            sub.pop_back();
        }
    }

    // Iterative
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        res.push_back(sub);
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }

    // Bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int resSize = (int)pow(2, n);
        vector<vector<int>> res(resSize, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < resSize; j++) {
                if ((j >> i) & 1) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }
};