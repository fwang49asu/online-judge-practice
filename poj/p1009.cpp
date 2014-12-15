#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

typedef struct RLEPair {
    int value;
    int position;
    int repeat;
}RLEPair;


class Image {
    public:
        int width, height, size;
        vector<RLEPair> data;
        
        Image() {
            width = 0;
        }
        int valueAt(int index) {
            // todo: binary search to find the value
            // now we just linear search...
            for(int i=1; ; ++i) {
                if(i >= data.size() || data[i].position > index) {
                    return data[i-1].value;
                }
            }
        }
        int diff(int index) {
            int centerValue = valueAt(index);
            int centerX = index % width;
            int centerY = index / width;

            int curMax = 0;
            for(int y = centerY - 1; y <= centerY + 1; ++y) {
                for(int x = centerX - 1; x <= centerX + 1; ++x) {
                    if(y >= 0 && y < height && x >= 0 && x < width) {
                        int subIndex = y * width + x;
                        int subValue = valueAt(subIndex);
                        int curDiff = abs(subValue - centerValue);
                        curMax = max(curDiff, curMax);
                    }
                }
            }
            return curMax;
        }
        void loadImage() {
            data.clear();
            int value, rep;
            cin >> value >> rep;
            int position = 0;
            while(!(value == 0 && rep == 0)) {
                RLEPair pair;
                pair.value = value;
                pair.position = position;
                pair.repeat = rep;
                position += rep;
                data.push_back(pair);
                cin >> value >> rep;
            }
            size = 0;
            for(int i=0; i<data.size(); ++i) {
                size += data[i].repeat;
            }
            height = size / width;
        }
        void print() {
            cout << width << endl;
            for(int i=0; i<data.size(); ++i) {
                cout << data[i].value << " " << data[i].repeat << endl;
            }
            cout << "0 0" << endl;
        }
};

void compute(Image &a, int index, map<int, int> &resultMap) {
    int centerX = index % a.width;
    int centerY = index / a.width;

    for(int y = centerY - 1; y <= centerY + 1; ++y) {
        for(int x = centerX - 1; x <= centerX + 1; ++x) {
            if(y >= 0 && y < a.height && x >= 0 && x < a.width) {
                int curIndex = y * a.width + x;
                if(resultMap.find(curIndex) == resultMap.end()) {
                    resultMap.insert(pair<int, int>(curIndex, a.diff(curIndex)));
                }
            }
        }
    }
}

void compute(Image &a, Image &b) {
    b.width = a.width;
    b.height = a.height;
    b.size = a.size;
    b.data.clear();
    map<int, int> resultMap;

    for(int i=0; i<a.data.size(); ++i) {
        RLEPair pair = a.data[i];
        int start = pair.position;
        int end = start + pair.repeat - 1;

        // only check the neighbors of start and end
        compute(a, start, resultMap);
        compute(a, end, resultMap);
    }
    resultMap.insert(pair<int, int>(b.size, -1));
    map<int, int>::iterator it = resultMap.begin();
    RLEPair curPair;
    curPair.position = it->first;
    curPair.value = it->second;

    for(++it; it != resultMap.end(); ++it) {
        // if the value is the same, just continue; otherwise, save the object
        if(curPair.value != it->second) {
            curPair.repeat = it->first - curPair.position;
            b.data.push_back(curPair);
            curPair.position = it->first;
            curPair.value = it->second;
        }
    }
}


int main() {
    Image image;
    Image result;
    int width = 0;
    cin >> width;
    while(width > 0) {
        image.width = width;
        image.loadImage();
        compute(image, result);
        result.print();
        cin >> width;
    }
    cout << 0 << endl;
    return 0;
}
