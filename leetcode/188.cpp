class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) {
            return 0;
        }
        if(k >= prices.size()) {
            int result = 0;
            for(int i=1; i<prices.size(); ++i) {
                if(prices[i] > prices[i-1]) {
                    result += prices[i]-prices[i-1];
                }
            }
            return result;
        }
        vector<int> buy;
        vector<int> sell;
        for(int i=0; i<k; ++i) {
            buy.push_back(INT_MIN);
            sell.push_back(0);
        }

        for(int x : prices) {
            for(int i=k-1; i>0; --i) {
                sell[i] = max(sell[i], buy[i] + x);
                buy[i] = max(buy[i], sell[i-1] - x);
            }
            sell[0] = max(sell[0], buy[0] + x);
            buy[0] = max(buy[0], -x);
        }

        return sell[k-1];
    }
};
