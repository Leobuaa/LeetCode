class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, size = nums.size();
        for (int i = 0; i < size; i++)
            res ^= nums[i];
        return res;
    }
};