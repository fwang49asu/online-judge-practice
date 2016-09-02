class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        if(root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        if(root->left == NULL) {
            return hasPathSum(root->right, sum - root->val);
        }
        if(root->right == NULL) {
            return hasPathSum(root->left, sum - root->val);
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
