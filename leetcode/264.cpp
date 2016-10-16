class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        --n;
        while(n > 0) {
            long long a = *(s.begin());
            s.erase(s.begin());
            s.insert(a*2);
            s.insert(a*3);
            s.insert(a*5);
            --n;
        }
        return (int)(*(s.begin()));
    }
};
