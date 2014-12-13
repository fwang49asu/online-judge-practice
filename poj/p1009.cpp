#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct RLEPair {
    int value;
    int position;
    int repeat;
}RLEPair;

class Image {
    public:
        int width;
        Image() {
            width = 0;
        }
        int value(int y, int x) {
            return 0;
        }
        void compressResult() {}
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
        }
        void print() {
            cout << width << endl;
            for(int i=0; i<data.size(); ++i) {
                cout << data[i].value << " " << data[i].repeat << endl;
            }
            cout << "0 0" << endl;
        }
    private:
        vector<RLEPair> data;
};

int main() {
    Image image;
    Image result;
    int width = 0;
    cin >> width;
    while(width > 0) {
        image.width = width;
        image.loadImage();
        image.print();
        cin >> width;
    }
    cout << 0 << endl;
    return 0;
}
