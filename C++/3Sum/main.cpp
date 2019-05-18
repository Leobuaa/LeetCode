class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0, last = int(nums.size()) - 1;
        while (i < last) {
            int front = i + 1, end = last;
            int target = -nums[i];
            while (front < end) {
                int b = nums[front], c = nums[end], sum = b + c;
                if (sum == target)
                    result.push_back({nums[i], nums[front], nums[end]});
                
                if (sum <= target) {
                    front++;
                    while ((front < end) && nums[front] == nums[front - 1]) front++;
                }
                
                if (sum >= target) {
                    end--;
                    while ((front < end) && nums[end] == nums[end + 1]) end--;
                }
             }
             i++;
             while ((i < last) && nums[i] == nums[i - 1])   i++;
        }
        return result;
    }
};