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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() <= 0) {
            return 0;
        }
        
        vector<Interval> res;
        vector<Interval> copyIntervals(intervals);
        auto comp = [](Interval x, Interval y) {
            // Actually, x.end < y.end is ok.
            return x.end < y.end || (x.end == y.end && x.start > y.start);
        };
        
        sort(copyIntervals.begin(), copyIntervals.end(), comp);
        res.push_back(copyIntervals[0]);
        for (int i = 1; i < copyIntervals.size(); i++) {
            Interval tmp = res.back();
            if (copyIntervals[i].start >= tmp.end) {
                res.push_back(copyIntervals[i]);
            }
        }
        
        return copyIntervals.size() - res.size();
    }
};