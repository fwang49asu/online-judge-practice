#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }
        vector<Node> vec(n);
        for(int i=0; i<n; ++i) {
            vec[i].val = nums[i];
            vec[i].next = i+1;
        }
        vec[n-1].next = -1;
        int cur = BucketSort(vec, 0);
        int next = vec[cur].next;
        int result = INT_MIN;
        while(next != -1) {
            int diff = vec[next].val - vec[cur].val;
            result = max(diff, result);
            cur = next;
            next = vec[next].next;
        }
        return result;
    }
private:
    struct Node {
        int next;
        int val;
    };
    int BucketSort(vector<Node>& vec, int head) {
        pair<int, int> empty_bucket = make_pair(-1, -1);
        int size = 1 << 4;
        int mask = size - 1;
        vector<pair<int, int>> cur_buckets(size, empty_bucket);
        vector<pair<int, int>> next_buckets(size, empty_bucket);
        cur_buckets[0].first = head;
        cur_buckets[0].first = head;
        for(int i=0; i<=8; ++i) {
            if(i==7) {
                mask = mask >> 1;
            }
            for(int k=0; k<size; ++k) {
                int cur = cur_buckets[k].first;
                while(cur != -1) {
                    int next = vec[cur].next;
                    // pick it
                    vec[cur].next = -1;
                    int pos = 0;
                    if(i <= 7) {
                        pos = (vec[cur].val >> (i*4)) & mask;
                    } else {
                        pos = vec[cur].val < 0 ? 0 : 1;
                    }
                    if(next_buckets[pos].first == -1) {
                        next_buckets[pos].first = cur;
                        next_buckets[pos].second = cur;
                    } else {
                        vec[next_buckets[pos].second].next = cur;
                        next_buckets[pos].second = cur;
                    }
                    cur = next;
                }
            }
            cur_buckets.swap(next_buckets);
            vector<pair<int, int>> v(size, empty_bucket);
            next_buckets.swap(v);
        }
        head = -1;
        int tail = -1;
        // only the first two
        for(int i=0; i<2; ++i) {
            if(cur_buckets[i].first != -1) {
                int cur = cur_buckets[i].first;
                while(cur != -1) {
                    int next = vec[cur].next;
                    if(head == -1) {
                        head = cur;
                        tail = cur;
                    } else {
                        vec[tail].next = cur;
                        tail = cur;
                    }
                    cur = next;
                }
            }
        }
        return head;
    }
};

int main() {
    return 0;
}
