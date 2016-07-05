class Solution {
public:
    void combinationSum2(vector<vector<int>> &res, vector<int> &com, int sum, int target, int start, vector<int>& candidates) {
        if (sum == target) {
            res.push_back(com);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            vector<int> tmp(com);
            tmp.push_back(candidates[i]);
            combinationSum2(res, tmp, sum + candidates[i], target, i + 1, candidates);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        combinationSum2(res, com, 0, target, 0, candidates);
        return res;
    }
};