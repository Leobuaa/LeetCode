class Solution {
public:
    void permuteUnique(vector<vector<int>> &res, vector<int> &permutation, vector<int> &nums) {
        if (nums.empty()) {
            res.push_back(permutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<int> tmpVector(permutation);
            int tmp = nums[i];
            
            permutation.push_back(tmp);
            nums.erase(nums.begin() + i);
            
            permuteUnique(res, permutation, nums);
            
            permutation.clear();
            permutation = tmpVector;
            nums.insert(nums.begin() + i, tmp);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> permutation;
        permuteUnique(res, permutation, nums);
        return res;
    }
};