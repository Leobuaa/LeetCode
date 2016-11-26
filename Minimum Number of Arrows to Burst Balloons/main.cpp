class Solution {
public:
    // My solution. It runs 
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1) {
            return points.size();
        }
        
        auto comp = [](const pair<int, int> &x, const pair<int, int> &y) {
            return x.first < y.first;
        };
        
        vector<pair<int, int>> copyPoints(points);
        sort(copyPoints.begin(), copyPoints.end(), comp);
        
        vector<pair<int, int>> res;
        res.push_back(copyPoints[0]);
        for (int i = 1; i < copyPoints.size(); i++) {
            auto tmp = res[res.size() - 1];
            if (tmp.second < copyPoints[i].first) {
                res.push_back(copyPoints[i]);
                continue;
            }
            
            res[res.size() - 1] = make_pair(max(tmp.first, copyPoints[i].first), min(tmp.second, copyPoints[i].second));
        }
        
        return res.size();
    }
};