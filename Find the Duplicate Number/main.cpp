class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    cnt1++;
                } else {
                    cnt2++;
                }
            }
            
            if (cnt1 > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};