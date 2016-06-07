class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }
        
        res.push_back({nums[0]});
        
        for (int i = 1; i < nums.size(); i++) {
            vector<vector<int>> tmpRes;
            for (int j = 0; j < res.size(); j++) {
                int len = res[j].size();
                for (int k = 0; k <= len; k++) {
                    vector<int> tmp(res[j]);
                    tmp.insert(tmp.begin() + k, nums[i]);
                    tmpRes.push_back(tmp);
                }
            }
            res.clear();
            res = tmpRes;
        }
        return res;
    }
};