class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int buy = INT32_MIN, preBuy = 0;
        int sell = 0, preSell = 0;
        for (int i = 0; i < len; i++)
        {
            preBuy = buy;
            buy = max(preBuy, preSell - prices[i]);
            preSell = sell;
            sell = max(preSell, preBuy + prices[i]);
        }
        return sell;
    }
};