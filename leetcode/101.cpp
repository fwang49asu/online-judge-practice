class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) {
            return true;
        }
        if(left != NULL && right != NULL) {
            if(left->val != right->val) {
                return false;
            }
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
        return false;
    }
};
