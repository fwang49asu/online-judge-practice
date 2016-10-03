class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL || root->left == NULL) {
            return root;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur->left != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        root = cur;
        while(!s.empty()) {
            TreeNode* prev = s.top();
            s.pop();
            cur->left = prev->right;
            cur->right = prev;
            cur = prev;
            prev->left = NULL;
            prev->right = NULL;
        }
        return root;
    }
};
