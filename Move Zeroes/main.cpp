class Solution {
public:
    // My first solution, it's not good, swap need more operation
    void moveZeroes(vector<int>& nums) {
        int i = 0, count = 0;
        int end = int (nums.size()) - 1;
        while (i <= end)
        {
            if (nums[i] != 0)
                swap(nums[count++], nums[i]);
            i++;
        }
    }

    // Improve my first solution
    void moveZeroes(vector<int>& nums) {
        int i = 0, count = 0;
        int end = int (nums.size()) - 1;
        while (i <= end)
        {
            if (nums[i] != 0 && i == count) {
                count++;
            } else if (nums[i] != 0) {
                swap(nums[count++], nums[i]);
            }
            i++;
        }
    } 

    // Another solution
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        for (; j < size; j++) {
            nums[j] = 0;
        }
    }
};