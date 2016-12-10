class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
private:
    int depthSum(const vector<NestedInteger>& nestedList, int depth) {
        int result = 0;
        for(auto p : nestedList) {
            if(p.isInteger()) {
                result += p.getInteger() * depth;
            } else {
                result += depthSum(p.getList(), depth + 1);
            }
        }
        return result;
    }
};
