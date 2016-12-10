class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.emplace(&nestedList, -1);
        step();
    }

    int next() {
        auto p = s.top();
        step();
        return (*(p.first))[p.second].getInteger();
    }

    bool hasNext() {
        return !s.empty();
    }

private:
    stack<pair<vector<NestedInteger>*, int>> s;
    void step() {
        while(!s.empty()) {
            auto p = s.top();
            vector<NestedInteger>& vec = *(p.first);
            int index = p.second + 1;
            if(index == vec.size()) {
                s.pop();
                continue;
            }
            s.top().second = index;
            if(vec[index].isInteger()) {
                return;
            }
            s.emplace(&(vec[index].getList()), -1);
        }
    }
};
