//Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<int> maxn(prices.size() - 1);
        maxn[prices.size() - 2] = prices.back();
        int maxd = prices.back();
        for (int i = prices.size() - 2;i >= 0;i--)
        {
            maxn[i] = maxd;
            if (prices[i] > maxd)
                maxd = prices[i];
        }
        maxd = 0;
        for (int i = 0;i < prices.size() - 1;i++){
            if (maxn[i] - prices[i] > maxd)
                maxd = maxn[i] - prices[i];
        }
        return maxd;
    }
};
