#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string result = "1";
            string buffer = "";
            for(int i=1; i<n; ++i) {
                char c = result[0];
                int count = 1;
                for(int k = 1; k<result.length(); ++k) {
                    if(c == result[k]) {
                        ++count;
                    } else {
                        buffer += to_string(count);
                        buffer += c;
                        count = 1;
                        c = result[k];
                    }
                }
                buffer += to_string(count);
                buffer += c;
                result.swap(buffer);
                buffer.clear();
            }
            return result;
        }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}
