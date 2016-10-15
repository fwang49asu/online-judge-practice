/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for(auto x: intervals) {
            ++m[x.start];
            --m[x.end];
        }
        int result = 0;
        int cur = 0;
        for(auto p: m) {
            cur += p.second;
            result = max(cur, result);
        }
        return result;
    }
};
