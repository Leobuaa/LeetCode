class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = people.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < size; i++) {
            res.push_back(make_pair(-1, -1));
        }
        
        sort(people.begin(), people.end());
        
        for (int i = 0; i < size; i++) {
            int temp = people[i].second;
            for (int j = 0; j < size; j++) {
                if (res[j].first == -1 && temp == 0) {
                    res[j].first = people[i].first;
                    res[j].second = people[i].second;
                    break;
                }
                
                if (temp > 0 && (res[j].first == -1 || res[j].first >= people[i].first)) {
                    temp--;
                }
            }
        }
        
        return res;
    }
};