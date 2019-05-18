class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();
        int minPrice = INT32_MAX;
        int maxProfit = 0;
        for (int i = 0; i < size; i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};