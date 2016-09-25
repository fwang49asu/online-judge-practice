#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        if(length == 0) {
            return 0;
        }
        int sum = 1;
        int pre_score = 1;
        int peak_index = 0;
        int peak_candy = 1;
        for(int i=1; i<length; ++i) {
            int score = 0;
            if(ratings[i] == ratings[i-1]) {
                score = 1;
                peak_index = i;
                peak_candy = score;
            } else if(ratings[i] > ratings[i-1]) {
                score = pre_score + 1;
                peak_index = i;
                peak_candy = score;
            } else {
                // make sure everybody gets one
                score = 1;
                if(pre_score == 1) {
                    // do we need to give the peak more candy?
                    if(peak_candy < (i - peak_index + 1)) {
                        sum += i - peak_index;
                        ++peak_candy;
                    } else {
                        sum += i - peak_index - 1;
                    }

                }
            }
            sum += score;
            pre_score = score;
        }
        return sum;
    }
};

int main() {
    int array[] = {1,3,4,3,2};
    vector<int> vec(array, array + 5);
    Solution s;
    s.candy(vec);
    cout << endl;
    return 0;
}
