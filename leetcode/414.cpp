class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int x: nums) {
            s.insert(x);
            if(s.size() > 3) {
                s.erase(s.begin());
            }
        }
        if(s.size() < 3) {
            auto it = s.end();
            --it;
            return *it;
        }
        return *(s.begin());
    }
};
