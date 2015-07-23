class Solution {
public:    
    int unlimited(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int profit=0;
        for(int i=0;i<prices.size()-1;i++){
            profit+=prices[i]<prices[i+1]?prices[i+1]-prices[i]:0;
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        if(prices.size()/2<=k)
            return unlimited(prices);
        vector<int> global(prices.size()+1,0);
        vector<int> local(prices.size()+1,0);
        for(int i=0;i<prices.size()-1;i++){
            int diff=prices[i+1]-prices[i];
            for(int j=k;j>=1;j--){
                local[j]=max(global[j-1]+max(0,diff),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
        }
        return global[k];
    }
};