class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        set<int> s(heaters.begin(), heaters.end());
        int result = 0;
        for(x : houses) {
            result = max(result, nearestDistance(s, x));
        }
        return result;
    }
    int nearestDistance(set<int>& s, int x) {
        auto it = s.lower_bound(x);
        if(it == s.end()) {
            return abs(*(s.rbegin()) - x);
        }
        pair<int, int> upper(*it, abs(x - *it));
        --it;
        if(it == s.end()) {
            return upper.second;
        }
        int distance = abs(x - *it);
        return min(upper.second, distance);
    }
};
