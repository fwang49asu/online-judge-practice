class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        sumTree(root, 0, result);
        return result;
    }
private:
    void sumTree(TreeNode* root, int cur, int& result) {
        int val = cur*10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            result += val;
            return;
        }
        if(root->left != NULL) {
            sumTree(root->left, val, result);
        }
        if(root->right != NULL) {
            sumTree(root->right, val, result);
        }
    }
};
