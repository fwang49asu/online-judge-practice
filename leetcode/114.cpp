class Solution {
public:
    void flatten(TreeNode* root) {
        flattenLast(root);
    }
private:
    TreeNode* flattenLast(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        if(root->left == NULL && root->right == NULL) {
            return root;
        }
        if(root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return flattenLast(root->right);
        }
        if(root->left == NULL) {
            return flattenLast(root->right);
        }
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* left = flattenLast(root->right);
        left->right = right;
        return flattenLast(right);
    }
};
