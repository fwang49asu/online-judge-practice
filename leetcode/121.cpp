class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {
            return 0;
        }
        int result = 0;
        int min_price = prices[0];
        for(int i=1; i<prices.size(); ++i) {
            min_price = min(prices[i], min_price);
            result = max(prices[i] - min_price, result);
        }
        return result;
    }
};
