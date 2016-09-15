#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        int buy[2];
        int sell[2];
        buy[0] = buy[1] = -prices[0];
        sell[0] = sell[1] = 0;
        for(int i=1; i<prices.size(); ++i) {
            int x = prices[i];
            sell[1] = max(sell[1], buy[1] + x);
            buy[1] = max(buy[1], sell[0] - x);
            sell[0] = max(sell[0], buy[0] + x);
            buy[0] = max(buy[0], -x);
        }
        return sell[1];
    }
};

int main() {
    int a[] = {2,7,4,1};
    vector<int> vec(a, a+4);
    Solution s;
    cout << s.maxProfit(vec) << endl;
    return 0;
}
