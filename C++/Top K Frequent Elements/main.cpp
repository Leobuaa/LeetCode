class Solution {
public:
    // Hash table
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]]++;
        }
        
        map<int, vector<int>> map2;
        for (auto pair : map1) {
            map2[pair.second].push_back(pair.first);
        }
        
        vector<int> res;
        for (auto pair = map2.rbegin(); pair != map2.rend(); pair++) {
            if (k <= 0) {
                break;
            }
            for (auto tmp : pair->second) {
                res.push_back(tmp);
                k--;
                if (k <= 0) {
                    break;
                }   
            }
        }
        return res;
    }
};