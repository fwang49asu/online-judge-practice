int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low < high) {
            int center = low + ((high - low) >> 1);
            int t = guess(center);
            if(t == 0) {
                return center;
            }
            if(t > 0) {
                low = center + 1;
            } else {
                high = center - 1;
            }
        }
        return low;
    }
};
