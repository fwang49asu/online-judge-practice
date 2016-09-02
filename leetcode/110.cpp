class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
private:
    bool isBalanced(TreeNode* root, int& depth) {
        if(root == NULL) {
            depth = 0;
            return true;
        }
        int leftDepth;
        bool leftResult = isBalanced(root->left, leftDepth);
        if(!leftResult) {
            return false;
        }
        int rightDepth;
        bool rightResult = isBalanced(root->right, rightDepth);
        if(!rightResult) {
            return false;
        }
        if(abs(leftDepth-rightDepth) > 1) {
            return false;
        }
        depth = max(leftDepth, rightDepth) + 1;
        return true;
    }
};
