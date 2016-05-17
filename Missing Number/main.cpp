class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            res = res ^ i ^ nums[i];
        res = res ^ size;

        return res;
    }
};