class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
};
