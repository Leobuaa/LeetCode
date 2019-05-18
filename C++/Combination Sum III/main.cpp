class Solution {
public:
    vector<vector<int>> combinationSum(int k, int n, int num) {
        vector<vector<int>> res;
        if (k == 1 && num <= n) {
            if (n <= 9) {
                vector<int> tmp = {n};
                res.push_back(tmp);
            }
            return res;
        }
        bool flag = (2 * num + k - 1) * k <= 2 * n ? true : false;
        while (flag) {
            vector<vector<int>> tmp = combinationSum(k - 1, n - num, num + 1);
            for (int i = 0; i < tmp.size(); i++) {
                tmp[i].insert(tmp[i].begin(), num);
                res.push_back(tmp[i]);
            }
            num++;
            flag = (2 * num + k - 1) * k <= 2 * n ? true : false;
        }
        return res;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        res = combinationSum(k, n, 1);
        return res;
    }
};