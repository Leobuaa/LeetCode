class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = 0;
    int i = 0, j = int(nums.size()) - 1;
    int min = INT_MAX;
    while (i < j - 1)
    {
        int l = i + 1, r = j;
        
         while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target)  return target;
            
            if (abs(sum - target) < min)
            {
                result = sum;
                min = abs(sum - target);
            }
            
            (sum < target)? l++ : r--;
        }

        
        i++;
    }
    
    return result;

    }
};