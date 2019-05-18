class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        solve(1, n, res);
        return res;
    }
    
    void solve(int target, int n, vector<int> &res) {
        if (target > n) {
            return;
        }
        res.push_back(target);
        solve(target * 10, n, res);
        if (target % 10 != 9) {
            solve(target + 1, n, res);
        }
    }
};