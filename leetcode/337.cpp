class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> cache;
        cache[NULL] = 0;
        return rob(root, cache);
    }
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& cache) {
        if(cache.find(root) != cache.end()) {
            return cache[root];
        }
        int skip = rob(root->left, cache) + rob(root->right, cache);
        int noskip = root->val;
        if(root->left != NULL) {
            noskip += rob(root->left->left, cache) + rob(root->left->right, cache);
        }
        if(root->right != NULL) {
            noskip += rob(root->right->left, cache) + rob(root->right->right, cache);
        }
        int result = max(skip, noskip);
        cache[root] = result;
        return result;
    }
};
