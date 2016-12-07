class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int diff = 1;
        for(int i=0; i<n; ++i) {
            --diff;
            if(diff < 0) {
                return false;
            }
            bool node = false;
            if(preorder[i] == '#') {
                ++i;
            } else {
                node = true;
                for(++i; i<n && preorder[i] != ','; ++i);
            }
            if(node) {
                diff += 2;
            }
        }
        return diff == 0;
    }
};
