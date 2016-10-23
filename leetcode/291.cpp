class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> left_map;
        unordered_map<string, char> right_map;
        return helper(0, 0, left_map, right_map, pattern, str);
    }
private:
    bool helper(int pattern_pos, int str_pos, unordered_map<char, string>& left_map, unordered_map<string, char>& right_map, string& pattern, string& str) {
        int pattern_n = pattern.length();
        int str_n = str.length();
        if(pattern_pos == pattern_n && str_pos == str_n) {
            return true;
        }
        if(pattern_pos == pattern_n || str_pos == str_n) {
            return false;
        }
        char pc = pattern[pattern_pos];
        if(left_map.find(pc) == left_map.end()) {
            for(int end = str_pos+1; end <= str_n; ++end) {
                string s = str.substr(str_pos, end - str_pos);
                if(right_map.find(s) != right_map.end()) {
                    continue;
                }
                left_map[pc] = s;
                right_map[s] = pc;
                if(helper(pattern_pos+1, end, left_map, right_map, pattern, str)) {
                    return true;
                }
                left_map.erase(pc);
                right_map.erase(s);
            }
        } else {
            string s = left_map[pc];
            string base = str.substr(str_pos, s.length());
            if(s == base) {
                return helper(pattern_pos+1, str_pos + s.length(), left_map, right_map, pattern, str);
            }
            return false;
        }

        return false;
    }
};
