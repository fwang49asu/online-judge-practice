class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        int min_y = INT_MAX;
        int max_y = INT_MIN;
        int area = 0;
        unordered_set<string> s;
        for(vector<int>& vec: rectangles) {
            min_x = min(vec[0], min_x);
            max_x = max(vec[2], max_x);
            min_y = min(vec[1], min_y);
            max_y = max(vec[3], max_y);

            {
                string str = to_string(vec[0]) + "_" + to_string(vec[1]);
                auto it = s.find(str);
                if(it == s.end()) {
                    s.insert(str);
                } else {
                    s.erase(it);
                }
            }
            {
                string str = to_string(vec[0]) + "_" + to_string(vec[3]);
                auto it = s.find(str);
                if(it == s.end()) {
                    s.insert(str);
                } else {
                    s.erase(it);
                }
            }
            {
                string str = to_string(vec[2]) + "_" + to_string(vec[1]);
                auto it = s.find(str);
                if(it == s.end()) {
                    s.insert(str);
                } else {
                    s.erase(it);
                }
            }
            {
                string str = to_string(vec[2]) + "_" + to_string(vec[3]);
                auto it = s.find(str);
                if(it == s.end()) {
                    s.insert(str);
                } else {
                    s.erase(it);
                }
            }

            area += (vec[3] - vec[1]) * (vec[2] - vec[0]);
        }
        {
            string str = to_string(min_x) + "_" + to_string(min_y);
            if(s.find(str) == s.end()) {
                return false;
            }
        }
        {
            string str = to_string(min_x) + "_" + to_string(max_y);
            if(s.find(str) == s.end()) {
                return false;
            }
        }
        {
            string str = to_string(max_x) + "_" + to_string(min_y);
            if(s.find(str) == s.end()) {
                return false;
            }
        }
        {
            string str = to_string(max_x) + "_" + to_string(max_y);
            if(s.find(str) == s.end()) {
                return false;
            }
        }
        return s.size() == 4 && area == (max_x - min_x) * (max_y - min_y);
    }
};
