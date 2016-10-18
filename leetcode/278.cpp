// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int high = n;
        int low = 1;
        while(low < high) {
            int center = low + ((high - low) >> 1);
            if(isBadVersion(center)) {
                high = center;
            } else {
                low = center + 1;
            }
        }
        return low;
    }
};
