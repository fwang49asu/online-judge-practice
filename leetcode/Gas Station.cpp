class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for(int i=0;i<gas.size();i++)
            diff.push_back(gas[i]-cost[i]);
        int left=0,start=0,sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=diff[i];
            left+=diff[i];
            if(sum<0){
                start=i+1;
                sum=0;
            }
        }
        if(left<0)
            return -1;
        else
            return start;
    }
};