#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> result;
            int carry = 1;
            int length = digits.size();
            for(int i=length - 1; i>=0; --i) {
                int t = digits[i] + carry;
                result.push_back(t % 10);
                carry = t / 10;
            }
            if(carry > 0) {
                result.push_back(carry);
            }
            length = result.size();
            int half = length / 2;
            for(int i=0; i<half; ++i) {
                int t = result[i];
                result[i] = result[length - 1 - i];
                result[length - 1 - i] = t;
            }
            return result;
        }
};

int main() {
    int array[] = {3, 4};
    vector<int> vec(array, array+2);
    Solution s;
    vector<int> result = s.plusOne(vec);
    for(int i=0; i<result.size(); ++i) {
        cout << result[i] << "\t";
    }
    cout << endl;
}
