class Solution {
public:
	// My first solution, it runs 36ms
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }

};