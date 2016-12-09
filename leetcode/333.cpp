class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        ResultBuffer result = largestBST(root);
        return abs(result.result);
    }
private:
    struct ResultBuffer{
        int result;
        int max_v;
        int min_v;
        ResultBuffer(int r, int mx, int mn) : result(r), max_v(mx), min_v(mn) {}
    };
    ResultBuffer largestBST(TreeNode* root) {
        if(root == NULL) {
            return ResultBuffer(0, INT_MIN, INT_MAX);
        }
        ResultBuffer left = largestBST(root->left);
        ResultBuffer right = largestBST(root->right);
        if(left.result < 0 || right.result < 0 || root->val < left.max_v || root->val > right.min_v) {
            return ResultBuffer(max(abs(left.result), abs(right.result)) * -1, 0, 0);
        } else {
            return ResultBuffer(left.result + right.result + 1, max(right.max_v, root->val), min(left.min_v, root->val));
        }
    }
};
