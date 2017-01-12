class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        vector<int> sortHeaters(heaters.begin(), heaters.end());
        sort(sortHeaters.begin(), sortHeaters.end());
        int res = 0, size = sortHeaters.size();
        for (int house : houses) {
            int l = 0, r = size - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (sortHeaters[mid] == house) {
                    l = mid;
                    break;
                }
                if (house < sortHeaters[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int minRadius = abs(house - sortHeaters[l]);
            if (l > 0) {
                minRadius = min(minRadius, abs(house - sortHeaters[l - 1]));
            }
            res = max(res, minRadius);
        }
        return res;
    }
};