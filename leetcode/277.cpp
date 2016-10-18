// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int result = 0;
        for(int i=1; i<n; ++i) {
            if(knows(result, i)) {
                result = i;
            }
        }
        // validate
        for(int i=0; i<n; ++i) {
            if(i == result) {
                continue;
            }
            if(!knows(i, result) || knows(result, i)) {
                return -1;
            }
        }
        return result;
    }
};
