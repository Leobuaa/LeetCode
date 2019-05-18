/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<int, int> map;
        for (int i = 0; i < intervals.size(); i++) {
            map[intervals[i].start] = i;
        }
        
        auto comp = [](Interval x, Interval y) {
            return x.start < y.start;
        };
        
        vector<Interval> originIntervals;
        for (auto x : intervals) {
            originIntervals.push_back(x);
        }
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> res;
        for (auto it : originIntervals) {
            int searchInt = it.end;
            
            int l = 0, r = intervals.size() - 1;
            
            while (l < r) {
                int mid = (l + r) >> 1;
                if (searchInt > intervals[mid].start) {
                   l = mid + 1;
                } else {
                   r = mid;
                }
            }
            
            if (searchInt > intervals[l].start) {
                res.push_back(-1);
            } else {
                res.push_back(map[intervals[l].start]);
            }
        }
        
        return res;
    }
};