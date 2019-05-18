class Solution {
public:
    // DP problem
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)  return 0;
        int sum = nums[0], res = nums[0];
        for (int i = 1; i < size; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }
        return res;
    }

    // Divide and conquear
    void maxSubArray(vector<int>& nums, int l, int r, int& lmx, int& rmx, int& mx, int& sum)
    {
        if (l == r)
            mx = lmx = rmx = sum = nums[l];
        else 
        {
            int mx1, mx2, lmx1, lmx2, rmx1, rmx2, sum1, sum2;
            int m = (l + r) >> 1;
            maxSubArray(nums, l, m, lmx1, rmx1, mx1, sum1);
            maxSubArray(nums, m + 1, r, lmx2, rmx2, mx2, sum2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            mx = max(mx1, max(mx2, rmx1 + lmx2));
            sum = sum1 + sum2;
        }
    }

    int maxSubArray(vector<int>& nums) {
        int lmx, rmx, mx, sum;
        maxSubArray(nums, 0, int(nums.size()) - 1, lmx, rmx, mx, sum);
        return mx;
    }
};