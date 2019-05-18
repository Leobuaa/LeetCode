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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int pos = 0;
        while (pos < intervals.size() && intervals[pos].start < newInterval.start) {
            pos++;
        }
        intervals.insert(intervals.begin() + pos, newInterval);
        vector<Interval> res = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        return res;
    }
    
};