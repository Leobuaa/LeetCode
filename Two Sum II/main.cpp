class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> res(2, 0);
            int n = numbers.size();
            int l = 0, r = n - 1;
            while (l < r) {
                if (numbers[l] + numbers[r] == target) {
                    break;
                }

                if (numbers[l] + numbers[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }

            res[0] = l + 1;
            res[1] = r + 1;

            return res;
        }
};
