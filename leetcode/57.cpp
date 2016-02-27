#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval> result;
            int n = intervals.size();

            if(n == 0) {
                result.push_back(newInterval);
                return result;
            }

            int i;
            for(i=0; i<n && intervals[i].end < newInterval.start; ++i) {
                result.push_back(intervals[i]);
            }
            
            for(; i<n && intervals[i].start <= newInterval.end; ++i) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            result.push_back(newInterval);
            for(; i<n; ++i) {
                result.push_back(intervals[i]);
            }
            return result;
        }
};

int main() {
    Solution s;
    vector<Interval> vec;
    vec.push_back(Interval(1, 2));
    vec.push_back(Interval(3, 5));
    vec.push_back(Interval(6, 7));
    vec.push_back(Interval(8, 10));
    vec.push_back(Interval(12, 16));

    vector<Interval> result = s.insert(vec, Interval(4, 9));
    for(int i=0; i<result.size(); ++i) {
        cout << result[i].start << "\t" << result[i].end << endl;
    }
    return 0;
}
