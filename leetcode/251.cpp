class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d = vec2d;
        row = 0;
        col = 0;
        for(; row < vec2d.size() && vec2d[row].size() == 0; ++row);
    }

    int next() {
        int result = vec2d[row][col++];
        if(col == vec2d[row].size()) {
            col = 0;
            for(++row; row < vec2d.size() && vec2d[row].size() == 0; ++row);
        }
        return result;
    }

    bool hasNext() {
        if(vec2d.empty()) {
            return false;
        }
        return vec2d.size() > row;
    }

private:
    vector<vector<int>> vec2d;
    int row;
    int col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
