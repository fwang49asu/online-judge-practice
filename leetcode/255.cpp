class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) {
            return true;
        }
        return verifyPreorder(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
    bool verifyPreorder(vector<int>& preorder, int left, int right, int low, int high) {
        if(left > right) {
            return true;
        }
        if(left == right) {
            return preorder[left] > low && preorder[left] < high;
        }
        int root = preorder[left];
        if(root < low || root > high) {
            return false;
        }
        int left_bound = left;
        if(preorder[left+1] < root) {
            for(left_bound = left+1; left_bound <= right && preorder[left_bound] < root; ++left_bound);
            --left_bound;
        }
        return verifyPreorder(preorder, left+1, left_bound, low, root)
            && verifyPreorder(preorder, left_bound+1, right, root, high);
    }
};
