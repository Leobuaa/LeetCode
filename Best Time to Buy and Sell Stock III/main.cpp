class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
        
        vector<vector<int>> status(2, vector<int>(4, 0));
        status[0][0] = status[0][2] = INT32_MIN;
        int cur = 0, next = 1;
        for (int i = 0; i < size; i++)
        {
            status[next][0] = max(status[cur][0], -prices[i]);
            status[next][1] = max(status[cur][1], status[cur][0] + prices[i]);
            status[next][2] = max(status[cur][2], status[cur][1] - prices[i]);
            status[next][3] = max(status[cur][3], status[cur][2] + prices[i]);
            swap(cur, next);
        }
        
        return max(status[cur][1], status[cur][3]);
    }
};