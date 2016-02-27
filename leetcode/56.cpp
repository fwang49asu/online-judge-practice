#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool mycomp(Interval& a, Interval& b) {
    return a.start < b.start;
}

class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> result;
            if(intervals.empty()) {
                return result;
            }
            sort(intervals.begin(), intervals.end(), mycomp);

            Interval cur = intervals[0];
            for(int i=1; i<intervals.size(); ++i) {
                if(intervals[i].start <= cur.end) {
                    cur.end = max(cur.end, intervals[i].end);
                } else {
                    result.push_back(cur);
                    cur = intervals[i];
                }
            }
            result.push_back(cur);
            return result;
        }
};

int main() {
    vector<Interval> vec(4);
    vec[0] = Interval(1, 3);
    vec[1] = Interval(2, 6);
    vec[2] = Interval(8, 10);
    vec[3] = Interval(15, 18);

    Solution s;
    vector<Interval> result = s.merge(vec);
    for(int i=0; i<result.size(); ++i) {
        cout << result[i].start << "\t" << result[i].end << endl;
    }
    return 0;
}
