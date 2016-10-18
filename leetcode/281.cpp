#include <vector>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vp[0] = &v1;
        vp[1] = &v2;
        size[0] = v1.size();
        size[1] = v2.size();
        x = 0;
        y = 0;
        if(v1.empty()) {
            y = 1;
        }
    }

    int next() {
        int result = vp[y]->at(x);
        if(y == 0) {
            if(x < size[1]) {
                ++y;
            } else {
                ++x;
            }
        } else {
            ++x;
            if(x < size[0]) {
                --y;
            }
        }
        return result;
    }

    bool hasNext() {
        return size[y] > x;
    }
private:
    vector<int>* vp[2];
    int size[2];
    int x;
    int y;
};
