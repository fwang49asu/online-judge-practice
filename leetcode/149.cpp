#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 2) {
            return points.size();
        }
        int result = 2;
        // float is NEVER accurate! I hate to use float/double as key
        unordered_map<int, int> slope_map;
        for(int i=points.size()-1; i>=result; --i) {
            slope_map.clear();
            int dup = 1;
            for(int k=0; k<i; ++k) {
                if(points[i].x == points[k].x) {
                    if(points[i].y == points[k].y) {
                        ++dup;
                    } else {
                        AddOne(slope_map, INT_MAX);
                    }
                } else {
                    double slope_f = points[i].y - points[k].y;
                    slope_f /= points[i].x - points[k].x;
                    slope_f = round(slope_f * 100000);
                    AddOne(slope_map, (int)slope_f);
                }
            }
            for(auto e : slope_map) {
                int cur = e.second + dup;
                result = max(cur, result);
            }
        }
        return result;
    }
private:
    void AddOne(unordered_map<int, int>& m, int key) {
        if(m.find(key) == m.end()) {
            m.insert(make_pair(key, 1));
        } else {
            ++m[key];
        }
    }
};

int main() {
    vector<Point> vec;
    return 0;
}
