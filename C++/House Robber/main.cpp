class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int a = 0, b = 0;
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
                a = max(b, a + nums[i]);
            else
                b = max(a, b + nums[i]);
        }
        return max(a, b);
    }
};