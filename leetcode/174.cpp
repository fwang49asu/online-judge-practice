#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int> hp(m, 0);
        hp[m-1] = dungeon[n-1][m-1] >= 0 ? 1 : (1-dungeon[n-1][m-1]);
        for(int i=m-2; i>=0; --i) {
            hp[i] = dungeon[n-1][i] >= hp[i+1] ? 1 : (hp[i+1] - dungeon[n-1][i]);
        }
        for(int i=n-2; i>=0; --i) {
            // last one
            hp[m-1] = dungeon[i][m-1] >= hp[m-1] ? 1 : (hp[m-1] - dungeon[i][m-1]);
            for(int k=m-2; k>=0; --k) {
                hp[k] = min(dungeon[i][k] > hp[k+1] ? 1 : (hp[k+1] - dungeon[i][k]),
                            dungeon[i][k] > hp[k] ? 1 : (hp[k] - dungeon[i][k]));
            }
        }
        return hp[0];
    }
};

int main() {
    return 0;
}
