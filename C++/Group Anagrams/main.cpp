class Solution {
public:
    // Hash table, it runs 76ms.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> sortedStrs = strs;
        unordered_map<string, vector<int>> strMap;
        
        for (int i = 0; i < strs.size(); i++) {
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
            strMap[sortedStrs[i]].push_back(i);
        }
        
        for (auto i = strMap.begin(); i != strMap.end(); i++) {
            vector<string> group;
            for (int j = 0; j < i->second.size(); j++) {
                group.push_back(strs[i->second[j]]);
            }
            sort(group.begin(), group.end());
            res.push_back(group);
        }
        
        return res;
    }
};