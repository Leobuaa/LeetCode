class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }
    
    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> res;
        int len = input.length();
        for (int i = 0; i < len; i++) {
            if (!isdigit(input[i])) {
                string s1 = input.substr(0, i), s2 = input.substr(i + 1);
                vector<int> res1, res2;
                if (dpMap.find(s1) != dpMap.end()) {
                    res1 = dpMap[s1];
                } else {
                    res1 = computeWithDP(s1, dpMap);
                }
                
                if (dpMap.find(s2) != dpMap.end()) {
                    res2 = dpMap[s2];
                } else {
                    res2 = computeWithDP(s2, dpMap);
                }
                
                for (auto num1 : res1) {
                    for (auto num2 : res2) {
                        if (input[i] == '+') {
                            res.push_back(num1 + num2);
                        } else if (input[i] == '-') {
                            res.push_back(num1 - num2);
                        } else {
                            res.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {
            res.push_back(stoi(input));
        }
        dpMap[input] = res;
        return res;
    }
};