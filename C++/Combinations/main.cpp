class Solution {
    // DFS
public:
    vector<vector<int>> combine(int n, int k) {
        tmp.resize(k);
        dfs(1, n, k);
        return res;
    }
private:
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(int start, int n, int k) {
        while (start <= n) {
            tmp[tmp.size() - k] = start++;
            if (k > 1) {
                dfs(start, n, k - 1);
            } else {
                res.push_back(tmp);
            }
        }
    }

    // Iterative 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> p(k, 0);
        int i = 0;
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) {
                i--;
            } else if (i == k - 1) {
                res.push_back(p);
            } else {
                i++;
                p[i] = p[i - 1];
            }
        }
        return res;
    }

    // Recursive
    vector<vector<int>> combine(int n, int start, int k) {
        vector<vector<int>> res;
        if (n - start + 1 < k || k <= 0) {
            return res;
        }
        
        if (k == 1) {
            for (int i = start; i <= n; i++) {
                res.push_back({i});
            }
            return res;
        }
        
        for (int i = start; i <= (n - k) + 1; i++) {
            vector<vector<int>> tmp = combine(n, i + 1, k - 1);
            for (auto &vec : tmp) {
                vec.insert(vec.begin(), i);
            }
            
            for (auto vec : tmp) {
                res.push_back(vec);
            }
        }
        
        return res;
    }

    vector<vector<int>> combine(int n, int k) {
        return combine(n, 1, k);
    }
};