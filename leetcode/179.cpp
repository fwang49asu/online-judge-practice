class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int max_num = 0;
        for(int x: nums) {
            max_num = max(x, max_num);
        }
        if(max_num == 0) {
            return "0";
        }
        vector<string> vec;
        for(int x: nums) {
            vec.push_back(to_string(x));
        }
        sort(vec.begin(), vec.end(), numstrcmp);
        stringstream ss;
        for(int i=vec.size()-1; i>=0; --i) {
            ss << vec[i];
        }
        return ss.str();
    }
    static bool numstrcmp(const string& a, const string& b) {
        // a<b return true
        string x = a + b;
        string y = b + a;
        return x.compare(y) < 0;
    }
};
