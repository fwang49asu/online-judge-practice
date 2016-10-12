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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) -> bool {
            if(a.start == b.start) {
                return a.end > b.end;
            }
            return a.start < b.start;
        });
        if(intervals.size() == 0) {
            return true;
        }
        int end = intervals[0].end;
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i].start < end) {
                return false;
            }
            end = intervals[i].end;
        }
        return true;
    }
};
