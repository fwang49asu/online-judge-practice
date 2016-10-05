class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tested;
        while(n != 1) {
            if(tested.find(n) != tested.end()) {
                return false;
            }
            tested.insert(n);
            n = next(n);
        }
        return true;
    }
private:
    int next(int n) {
        int result = 0;
        while(n != 0) {
            int t = n % 10;
            result += t * t;
            n /= 10;
        }
        return result;
    }
};
