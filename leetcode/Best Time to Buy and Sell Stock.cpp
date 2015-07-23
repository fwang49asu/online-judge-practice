class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int minVal=prices[0];
        int maxProfit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            maxProfit=max(maxProfit,prices[i]-minVal);
            minVal=min(minVal,prices[i]);
        }
        return maxProfit;
    }
};