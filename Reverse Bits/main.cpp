class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1;
        uint32_t res = n & mask;
        for (int i = 0; i < 31; i++)
        {
            mask <<= 1;
            res <<= 1;
            if (n & mask) {
                res++;
            }
        }
        return res;
    }
};