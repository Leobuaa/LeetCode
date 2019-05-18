class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0, last = 0;
        while (start <= last && start < nums.size()) {
            last = max(last, start + nums[start]);
            if (start == last) {
                break;
            }
            start++;
        }
        
        return last >= nums.size() - 1;
    }
};