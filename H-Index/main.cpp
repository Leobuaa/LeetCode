class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
            return 0;
        }
        
        int size = citations.size();
        vector<int> cnt(size + 1, 0);
        for (int i = 0; i < size; i++) {
            if (citations[i] >= size) {
                cnt[size]++;
            } else {
                cnt[citations[i]]++;
            }
        }
        
        int sum = 0;
        int res = 0;
        for (int i = size; i >= 0; i--) {
            sum += cnt[i];
            if (sum >= i) {
                res = i;
                break;
            }
        }
        return res;
    }
};