class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        for (int number : nums) {
            auto p = lower_bound(res.begin(), res.end(), number);
            if (p == res.end()) {
                res.push_back(number);
                if (res.size() == 3) {
                    return true;
                }
            } else {
                *p = number;
            }
        }
        return false;
    }
};