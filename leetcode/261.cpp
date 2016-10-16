class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_set<int> s;
        int size = edges.size();
        if(n == 0 || n == 1) {
            return edges.empty();
        }
        if(edges.size() != n-1) {
            return false;
        }
        s.insert(edges.back().first);
        s.insert(edges.back().second);
        int last = size-2;
        while(s.size() < n) {
            int i = last;
            for(; i >= 0 && !(s.find(edges[i].first) == s.end() ^ s.find(edges[i].second) == s.end()); --i);
            // cannot find one
            if(i < 0) {
                return false;
            }
            if(i != last) {
                swap(edges[i], edges[last]);
            }
            s.insert(edges[last].first);
            s.insert(edges[last].second);
            --last;
        }
        return true;
    }
};
