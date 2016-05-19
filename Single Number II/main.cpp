class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b0 = 0, b1 = 0, reset = 0;
        for (int i = 0; i < nums.size(); i++) {
            b1 = b1 | (nums[i] & b0);
            b0 = b0 ^ nums[i];
            reset = b0 & b1;
            b0 = b0 ^ reset;
            b1 = b1 ^ reset;
        }
        return b0;
    }

    int singleNumber(vector<int>& nums) {
        int size = int(nums.size());
        if (size == 1)  return nums[0];
        int mask = 1;
        int res = 0;
        for (int i = 0; i < 32; i++, mask <<= 1)
        {
            int count = 0;
            for (int j = 0; j < size; j++)
                if (nums[j] & mask)  count++;
            count %= 3;
            if (count)  res |= mask;
        }
        return res;
    }
};