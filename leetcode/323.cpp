class UnionSet {
public:
    UnionSet(int n) {
        for(int i=0; i<n; ++i) {
            parent.push_back(i);
        }
        size = n;
    }
    int GetClass(int x) {
        int p = x;
        while(p != parent[p]) {
            p = parent[p];
        }
        int result = p;
        // compress the path
        p = x;
        while(p != parent[x]) {
            p = parent[x];
            parent[x] = result;
        }
        return result;
    }
    void Merge(int a, int b) {
        int pa = GetClass(a);
        int pb = GetClass(b);
        if(pa == pb) {
            return;
        }
        --size;
        parent[pb] = pa;
    }
    int size;
private:
    vector<int> parent;
};
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UnionSet s(n);
        for(auto e: edges) {
            s.Merge(e.first, e.second);
        }
        return s.size;
    }
};
