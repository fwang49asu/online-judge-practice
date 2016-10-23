class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int count = 0;
        int n = rooms.size();
        if(n == 0) {
            return;
        }
        int m = rooms[0].size();
        vector<pair<int, int>> vec;
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(rooms[i][k] == INT_MAX) {
                    ++count;
                }
                if(rooms[i][k] == 0) {
                    vec.push_back(make_pair(i, k));
                }
            }
        }
        int dist = 1;
        while(count > 0 && !vec.empty()) {
            vector<pair<int, int>> next;
            for(p: vec) {
                int i = p.first;
                int k = p.second;
                int x;
                int y;
                y = i - 1;
                x = k;
                if(y >= 0 && rooms[y][x] == INT_MAX) {
                    rooms[y][x] = dist;
                    --count;
                    next.push_back(make_pair(y, x));
                }
                y = i + 1;
                x = k;
                if(y < n && rooms[y][x] == INT_MAX) {
                    rooms[y][x] = dist;
                    --count;
                    next.push_back(make_pair(y, x));
                }
                y = i;
                x = k - 1;
                if(x >= 0 && rooms[y][x] == INT_MAX) {
                    rooms[y][x] = dist;
                    --count;
                    next.push_back(make_pair(y, x));
                }
                y = i;
                x = k + 1;
                if(x < m && rooms[y][x] == INT_MAX) {
                    rooms[y][x] = dist;
                    --count;
                    next.push_back(make_pair(y, x));
                }
            }
            vec.swap(next);
            ++dist;
        }
    }
};
