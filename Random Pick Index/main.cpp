class Solution {
public:
    vector<int> n;

    Solution(vector<int> nums) {
        n = nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == target) {
                if ((rand() % (cnt + 1)) == cnt) {
                    res = i;
                }
                cnt++;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */