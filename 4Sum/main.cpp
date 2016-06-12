class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int begin = 0, end = int(nums.size()) - 1;
    
    int a = begin;
    while (a < end)
    {
        if (a > end - 3)    break;
        if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
        if (nums[end] + nums[end - 1] + nums[end - 2] + nums[end - 3] < target) break;
        
        int b = a + 1;
        while (b < end)
        {
            if (b > end - 2)    break;
            int sum1 = nums[a] + nums[b];
            int l = b + 1, r = end;
            if (sum1 + nums[l] + nums[l + 1] > target)  break;
            if (nums[a] + nums[r] + nums[r - 1] + nums[r - 2] < target) break;
            while (l < r)
            {
                if (sum1 + nums[l] + nums[l + 1] > target)  break;
                if (sum1 + nums[r] + nums[r - 1] < target)  break;
                int sum2 = nums[l] + nums[r];
                if (sum1 + sum2 == target)
                    result.push_back({nums[a], nums[b], nums[l], nums[r]});
                if (sum1 + sum2 <= target)
                {
                    l++;
                    while ((l < r) && (nums[l] == nums[l - 1])) l++;
                }
                if (sum1 + sum2 >= target)
                {
                    r--;
                    while ((l < r) && (nums[r] == nums[r + 1])) r--;
                }
            }
            b++;
            while ((b < end) && (nums[b] == nums[b - 1]))   b++;
        }
        
        a++;
        while ((a < end) && (nums[a] == nums[a - 1]))   a++;
    }
    return result;        
    }
};