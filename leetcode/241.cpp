class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> buffer_map;
        vector<int> result = GetResultVec(input, buffer_map);
        sort(result.begin(), result.end());
        return result;
    }
private:
    vector<int>& GetResultVec(string input, unordered_map<string, vector<int>>& buffer_map) {
        if(buffer_map.find(input) != buffer_map.end()) {
            return buffer_map[input];
        }
        vector<int> result;
        int n = input.length();
        bool has_operator = false;
        for(int i=0; i<n; ++i) {
            if(input[i] == '+') {
                has_operator = true;
                string left = input.substr(0, i);
                string right = input.substr(i+1, n-i);
                auto left_set = GetResultVec(left, buffer_map);
                auto right_set = GetResultVec(right, buffer_map);
                for(int a : left_set) {
                    for(int b : right_set) {
                        result.push_back(a+b);
                    }
                }
            }
            if(input[i] == '-') {
                has_operator = true;
                string left = input.substr(0, i);
                string right = input.substr(i+1, n-i);
                auto left_set = GetResultVec(left, buffer_map);
                auto right_set = GetResultVec(right, buffer_map);
                for(int a : left_set) {
                    for(int b : right_set) {
                        result.push_back(a-b);
                    }
                }
            }
            if(input[i] == '*') {
                has_operator = true;
                string left = input.substr(0, i);
                string right = input.substr(i+1, n-i);
                auto left_set = GetResultVec(left, buffer_map);
                auto right_set = GetResultVec(right, buffer_map);
                for(int a : left_set) {
                    for(int b : right_set) {
                        result.push_back(a*b);
                    }
                }
            }
        }
        if(!has_operator) {
            result.push_back(stoi(input));
        }
        buffer_map.insert(make_pair(input, result));
        return buffer_map[input];
    }
};
