class Solution {
    vector<int> origin, res;
public:
    Solution(vector<int> nums) {
        srand(time(0));
        origin.resize(nums.size());
        res.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            origin[i] = res[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = res.size() - 1; i >= 0; i--) {
            swap(res[rand() % (i + 1)], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */