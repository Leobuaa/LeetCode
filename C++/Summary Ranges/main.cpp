class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = int (nums.size()), i = 0, r;
        vector<string> res;
        if (size <= 0)   return res;
        while (i < size)
        {
            r = i;
            while (r < size - 1 && nums[r + 1] - nums[r] == 1)
                r++;
            if (r > i)
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[r]));
            else
                res.push_back(to_string(nums[i]));
            i = r > i ? ++r : ++i;
         }
         
        return res;
    }
};