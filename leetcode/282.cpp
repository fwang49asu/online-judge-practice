class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        int n = num.length();
        limit = to_string(INT_MAX);
        for(int i=0, cur = 1; i<n && cur != 0; ++i) {
            string s = num.substr(0, i+1);
            if(s.length() > limit.length()||(s.length() == limit.length() && s.compare(limit) > 0)) {
                break;
            }
            cur = stoi(s);
            search(i+1, 0, cur, s, num, target, result);
        }
        return result;
    }
private:
    void search(int pos, int sum, int last, string buffer, string& num, int target, vector<string>& result) {
        int n = num.length();
        if(pos == n) {
            if((sum + last) == target) {
                result.push_back(buffer);
            }
            return;
        }
        for(int i=pos, cur=1; i<n && cur != 0; ++i) {
            string s = num.substr(pos, i - pos + 1);
            if(s.length() > limit.length()||(s.length() == limit.length() && s.compare(limit) > 0)) {
                break;
            }
            cur = stoi(s);
            search(i+1, sum+last, cur, buffer + '+' + s, num, target, result);
            search(i+1, sum+last, -cur, buffer + '-' + s, num, target, result);
            search(i+1, sum, cur*last, buffer + '*' + s, num, target, result);
        }
    }
    string limit;
};
