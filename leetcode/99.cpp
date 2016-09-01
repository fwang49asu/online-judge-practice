class Solution {
public:
    void recoverTree(TreeNode* root) {
        mode = 0;
        inorder(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
private:
    // 0: find the left most
    // 1: find the first error
    // 2: find the second error
    int mode;
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);
        output(root);
        if(mode == 3) {
            return;
        }
        inorder(root->right);
    }
    void output(TreeNode* root) {
        switch(mode) {
            case 0:
                prev = root;
                ++mode;
                break;
            case 1:
                if(prev->val > root->val) {
                    first = prev;
                    ++mode;
                    second = root;
                }
                prev = root;
                break;
            case 2:
                if(root->val < second->val) {
                    second = root;
                }
                break;
        }
    }
};
