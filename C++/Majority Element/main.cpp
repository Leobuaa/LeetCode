class Solution {
public:
    // Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int curIndex = 0, cnt = 1;
        int size = (int)nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[curIndex]) {
                cnt++;
            } else {
                cnt--;
            }
            
            if (cnt == 0) {
                curIndex = i;
                cnt = 1;
            }
        }
        return nums[curIndex];
    }
};