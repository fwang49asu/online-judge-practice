class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> result;
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0; i<n; ++i) {
            addPair(equations[i], values[i], m);
        }
        for(auto p: queries) {
            result.push_back(query(p, m));
        }
        return result;
    }

    void addPair(pair<string, string> equation, double value, unordered_map<string, unordered_map<string, double>>& m) {
        m[equation.second][equation.first] = 1.0 / value;
        m[equation.first][equation.second] = value;
        m[equation.first][equation.first] = 1.0;
        m[equation.second][equation.second] = 1.0;
    }

    double query(pair<string, string> q, unordered_map<string, unordered_map<string, double>>& m) {
        unordered_set<string> used;
        if(m[q.first].empty()) {
            return -1;
        }
        if(q.first == q.second) {
            return 1;
        }
        queue<string> next;
        unordered_map<string, double> cache;
        cache[q.first] = 1;
        next.push(q.first);
        while(!next.empty()) {
            string cur = next.front();
            next.pop();
            double val = cache[cur];
            if(m.find(cur) == m.end()) {
                continue;
            }
            unordered_map<string, double>& dic = m[cur];
            for(auto entry: dic) {
                if(cache.find(entry.first) != cache.end()) {
                    continue;
                }
                if(entry.first == q.second) {
                    return val * entry.second;
                }
                cache[entry.first] = val * entry.second;
                next.push(entry.first);
            }
        }
        return -1;
    }
};
