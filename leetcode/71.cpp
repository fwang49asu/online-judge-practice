#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> vec;
            int low = 0;
            int high = 0;
            int length = path.length();
            while(low < length) {
                if(path[low] == '/') {
                    ++low;
                    continue;
                }
                for(high = low; high < length && path[high] != '/'; ++high);
                string str = path.substr(low, high - low);
                if(str.compare("..") == 0) {
                    if(vec.size() > 0) {
                        vec.pop_back();
                    }
                } else if(str.compare(".") != 0) {
                    vec.push_back(str);
                }
                low = high+1;
            }
            if(vec.size() == 0) {
                return "/";
            } else {
                string result = "";
                for(int i=0; i<vec.size(); ++i) {
                    result += "/";
                    result += vec[i];
                }
                return result;
            }
        }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}
