class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        int gas_sum = 0;
        int cost_sum = 0;
        int balance = 0;
        int start = 0;
        for(int i=0; i<length; ++i) {
            gas_sum += gas[i];
            cost_sum += cost[i];
            balance += gas[i] - cost[i];
            if(balance < 0) {
                // broke... try next
                start = i+1;
                balance = 0;
            }
        }
        if(gas_sum >= cost_sum) {
            return start;
        }

        return -1;
    }
};
