class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = int (nums.size());
        if (size <= 1)   return size;
        int res = 1;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[res++] = nums[i];
        }
        return res;
    }
};