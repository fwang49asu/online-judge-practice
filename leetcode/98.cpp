class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, ((long long)INT_MIN)-1, ((long long)INT_MAX)+1);
    }
private:
    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if(root == NULL) {
            return true;
        }
        long long val = (long long)root->val;
        if(val >= upper || val <= lower) {
            return false;
        }
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};
