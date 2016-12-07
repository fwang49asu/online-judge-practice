class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> edge_map;
        for(auto p: tickets) {
            edge_map[p.first].insert(p.second);
        }
        vector<string> result;
        dfs("JFK", edge_map, result);
        for(int low = 0, high = tickets.size(); low < high; ++low, --high) {
            swap(result[low], result[high]);
        }
        return result;
    }

    void dfs(string node, unordered_map<string, multiset<string>>& edge_map, vector<string>& result) {
        multiset<string>& s = edge_map[node];
        while(!s.empty()) {
            string next = *(s.begin());
            s.erase(s.begin());
            dfs(next, edge_map, result);
        }
        result.push_back(node);
    }
};
