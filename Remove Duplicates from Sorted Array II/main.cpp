class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int p1 = 0, p2 = p1 + 2;
        int cnt = 2;
        while (p2 < nums.size()) {
            if (nums[p2] != nums[p1]) {
                cnt++;
                p1++;
                p2++;
            } else {
                nums.erase(nums.begin() + p2);
            }
        }
        return cnt;
    }
};