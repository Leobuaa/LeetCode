class Solution {
public:
    unordered_map<string, unordered_map<string, double>> hash;
    unordered_map<string, bool> used;

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int size = queries.size();
        vector<double> res(size, 0.0);
        for (int i = 0; i < equations.size(); i++) {
            auto p = equations[i];
            hash[p.first][p.second] = values[i];
            hash[p.second][p.first] = 1 / values[i];
        }

        for (int i = 0; i < size; i++) {
            if (hash.find(queries[i].first) == hash.end() || hash.find(queries[i].second) == hash.end()) {
                res[i] = -1.0;
                continue;
            }
            find(1.0, res, queries[i].first, queries[i].second, i);
            if (res[i] == 0) {
                res[i] = -1.0;
            }
        }

        return res;
    }

    void find(double cur, vector<double> &res, string s, string t, int i) {
        if (res[i] != 0) {
            return;
        }

        if (hash.find(s) == hash.end() ) {
            res[i] = -1.0;
            return;
        } else {
            if (s == t) {
                res[i] = cur;
                return;
            } else {
                auto tmp = hash[s];
                used[s] = true;
                for (auto &p : hash[s] ) {
                    if (used.find(p.first) == used.end() || used[p.first] == false) {
                        used[p.first] = true;
                        find(cur * p.second, res, p.first, t, i);
                        used[p.first] = false;
                    }
                }
                used[s] = false;
            }
        }

    }
};
