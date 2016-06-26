class Solution {
public:
    // Backtracking, (red-black tree) set, recursive
    void combinationSum(vector<vector<int>>& res, vector<int>& combination, int sum, auto start, set<int>& cand) {
        if (sum == 0) {
            res.push_back(combination);
            return;
        }
        
        for (auto i = start; i != cand.end(); i++) {
            if (sum < *i) {
                break;
            }
            combination.push_back(*i);
            combinationSum(res, combination, sum - *i, i, cand);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> cand(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(res, combination, target, cand.begin(), cand);
        return res;
    }
};