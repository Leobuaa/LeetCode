class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size, 1);
        
        int begin = 1, end = 1;
        for (int i = 0; i < size; i++)
        {
            output[i] *= begin;
            begin *= nums[i];
            output[size - i - 1] *= end;
            end *= nums[size - i - 1];
        }
        
        return output;
    }
};