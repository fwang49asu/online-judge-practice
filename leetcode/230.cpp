class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = NULL;
        Inorder(root, k, result);
        return result->val;
    }
private:
    void Inorder(TreeNode* root, int& k, TreeNode*& result) {
        if(result != NULL) {
            return;
        }
        if(root->left != NULL) {
            Inorder(root->left, k, result);
        }
        --k;
        if(k == 0) {
            result = root;
            return;
        }
        if(root->right != NULL) {
            Inorder(root->right, k, result);
        }
    }
};
