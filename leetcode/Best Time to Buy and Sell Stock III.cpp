class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> ltor(prices.size(),0);
        vector<int> rtol(prices.size(),0);
        int minVal=prices[0];
        int maxProfit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            maxProfit=max(maxProfit,prices[i]-minVal);
            minVal=min(minVal,prices[i]);
            ltor[i]=maxProfit;
        }
        int maxVal=prices[prices.size()-1];
        maxProfit=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            maxProfit=max(maxProfit,maxVal-prices[i]);
            maxVal=max(maxVal,prices[i]);
            rtol[i]=maxProfit;
        }
        int res=INT_MIN;
        for(int i=0;i<prices.size();i++){
            res=max(res,ltor[i]+rtol[i]);
        }
        return res;
    }
};