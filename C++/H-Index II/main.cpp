class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size() - 1;
        int size = citations.size();
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (citations[mid] >= size - mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return size - l;
    }
};