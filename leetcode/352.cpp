/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if(range_map.empty()) {
            range_map[val] = val;
            return;
        }
        auto it = range_map.upper_bound(val);
        if(it == range_map.end()) {
            auto prev = range_map.rbegin();
            if(prev->second >= val) {
                return;
            }
            if(prev->second == (val - 1)) {
                prev->second = val;
                return;
            }
            range_map[val] = val;
            return;
        }
        auto prev = it;
        --prev;
        if(prev != range_map.end() && prev->first <= val && prev->second >= val) {
            return;
        }
        if(prev != range_map.end()  && prev->second == (val - 1)) {
            prev->second = val;
        } else {
            range_map[val] = val;
            prev = range_map.find(val);
        }
        if(it->first == (val + 1)) {
            prev->second = it->second;
            range_map.erase(it->first);
        }
    }

    vector<Interval> getIntervals() {
        vector<Interval> vec;
        for(auto p: range_map) {
            vec.emplace_back(p.first, p.second);
        }
        return vec;
    }
private:
    map<int, int> range_map;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
