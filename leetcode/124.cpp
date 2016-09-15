class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        pair<int, int> result = helper(root);
        return max(result.first, result.second);
    }
private:
    pair<int, int> helper(TreeNode* root) {
        pair<int, int> result(0, 0);
        if(root == NULL) {
            return result;
        }

        result.first = root->val;
        result.second = INT_MIN;

        if(root->left == NULL && root->right == NULL) {
            return result;
        }

        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);

        if(root->left != NULL && root->right != NULL) {
            result.second = max(result.second, root->val + left.first + right.first);
        }
        if(root->left != NULL) {
            result.first = max(result.first, root->val + left.first);
            result.second = max(result.second, left.first);
            result.second = max(result.second, left.second);
        }
        if(root->right != NULL) {
            result.first = max(result.first, root->val + right.first);
            result.second = max(result.second, right.first);
            result.second = max(result.second, right.second);
        }

        return result;
    }
};
