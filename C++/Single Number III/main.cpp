class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res1 = 0, res2 = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            res1 ^= nums[i];
        }
        
        int mask = 1;
        while ((res1 & mask) == 0)
            mask <<= 1;
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] & mask)
                res2 ^= nums[i];
        
        return {res2, res2 ^ res1};
    }
};