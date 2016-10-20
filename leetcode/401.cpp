class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> bit_vec;
        helper(result, bit_vec, 0, num);
        return result;
    }
private:
    void helper(vector<string>& result, vector<int>& bit_vec, int low, int num) {
        if(num == 0) {
            string s = GetCode(bit_vec);
            if(s != "") {
                result.push_back(GetCode(bit_vec));
            }
            return;
        }
        for(int i=low; i<11 - num; ++i) {
            bit_vec.push_back(i);
            helper(result, bit_vec, i+1, num-1);
            bit_vec.pop_back();
        }
    }
    string GetCode(vector<int>& vec) {
        int hour = 0;
        int minute = 0;
        for(int x: vec) {
            if(x < 4) {
                hour |= 1 << x;
            } else {
                minute |= 1 << (x - 4);
            }
        }
        if(hour > 11 || minute > 59) {
            return "";
        }
        return to_string(hour) + ":" + to_string(minute/10) + to_string(minute % 10);
    }
};
