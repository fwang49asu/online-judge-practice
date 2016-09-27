class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> state_stack;
        vector<int> result;
        state_stack.push(make_pair(root, 0));
        while(!state_stack.empty()) {
            auto entry = state_stack.top();
            state_stack.pop();
            if(entry.first == NULL || entry.second == 3) {
                continue;
            }
            ++entry.second;
            state_stack.push(entry);
            switch(entry.second) {
            case 1:
                result.push_back(entry.first->val);
                break;
            case 2:
                state_stack.push(make_pair(entry.first->left, 0));
                break;
            case 3:
                state_stack.push(make_pair(entry.first->right, 0));
                break;
            }
        }
        return result;
    }
};
