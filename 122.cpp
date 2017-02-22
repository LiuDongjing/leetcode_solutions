//Best Time to Buy and Sell Stock II
/*
 找价格连续上升的区段即可。其实很好理解，想想价格变化的折线图，把所有
 价格上升的区段买下来，就是把所有的盈利空间都占了。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int p = 0;
        int low = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] >= prices[i-1]) continue;
            p += (prices[i-1] - prices[low]);
            low = i;
        }
        if(low < prices.size() - 1) p += (prices.back() - prices[low]);
        return p;
    }
};