class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> res(11, 0);
        res[0] = 1;
        n = n > 10 ? 10 : n;
        for (int i = 1; i <= n; i++) {
            int tmp = 9, cnt = 9;
            for (int j = 1; j < i; j++) {
                tmp *= cnt;
                cnt--;
            }
            res[i] = tmp;
        }
        
        int sum = 0;
        for (int i : res) {
            sum += i;
        }
        
        return sum;
    }
};