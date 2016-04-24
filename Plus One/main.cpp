class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = int (digits.size());
        for (int i = size - 1; i >= 0; i--)
        {
            digits[i]++;
            if (digits[i] < 10)    break;
            digits[i] = 0;
        }
        if (digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};