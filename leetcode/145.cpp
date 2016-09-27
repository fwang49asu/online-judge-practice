class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> state_stack;
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        state_stack.push(root);
        TreeNode* prev = NULL;
        while(!state_stack.empty()) {
            TreeNode* cur = state_stack.top();
            if(prev == NULL || prev->left == cur || prev->right == cur) {
                if(cur->left != NULL) {
                    state_stack.push(cur->left);
                } else if(cur->right != NULL) {
                    state_stack.push(cur->right);
                }
            } else if(cur->left == prev) {
                if(cur->right != NULL) {
                    state_stack.push(cur->right);
                }
            } else {
                result.push_back(cur->val);
                state_stack.pop();
            }
            prev = cur;
        }
        return result;
    }
};
