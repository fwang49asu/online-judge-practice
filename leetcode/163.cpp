#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        // no intersection
        int n = nums.size();
        if(n == 0 || upper < nums[0] || lower > nums[n-1]) {
            result.push_back(BuildString(make_pair(lower, upper)));
            return result;
        }
        // lower side
        // find the lower position
        int start = bisearch_range(nums, 0, n-1, lower);
        pair<int, int> p;
        for(int i=start; i<n && lower <= upper; ++i) {
            if(lower < nums[i]) {
                p.first = lower;
                p.second = nums[i]-1;
                result.push_back(BuildString(p));
            }
            lower = nums[i]+1;
        }
        if(lower <= upper) {
            p.first = lower;
            p.second = upper;
            result.push_back(BuildString(p));
        }
        return result;
    }
private:
    int bisearch_range(vector<int>& nums, int low, int high, int value) {
        if(value <= nums[low]) {
            return low;
        }
        if(value > nums[high]) {
            return high+1;
        }
        int center = (low + high) >> 1;
        if(value <= nums[center]) {
            if(center == 0 || value > nums[center-1]) {
                return center;
            }
            return bisearch_range(nums, low, center-1, value);
        }
        return bisearch_range(nums, center+1, high, value);
    }
    string BuildString(const pair<int, int>& p) {
        string s = to_string(p.first);
        if(p.first == p.second) {
            return s;
        }
        return s + "->" + to_string(p.second);
    }
};

int main() {
    int array[] = {0, 1, 3, 50, 75};
    vector<int> vec(array, array+5);
    Solution s;
    vector<string> v = s.findMissingRanges(vec, -1, 99);
    for(string x: v) {
        cout << x << endl;
    }
    return 0;
}
