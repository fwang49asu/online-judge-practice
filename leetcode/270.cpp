/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(root == NULL) {
            return INT_MAX;
        }
        if(root->val == target) {
            return root->val;
        }
        double diff_root = abs(target - root->val);
        if(target > root->val && root->right != NULL) {
            int right = closestValue(root->right, target);
            double diff_right = abs(target - right);
            if(diff_right < diff_root) {
                return right;
            }
            return root->val;
        }
        if(root->left == NULL) {
            return root->val;
        }
        int left = closestValue(root->left, target);
        double diff_left = abs(target - left);
        if(diff_left < diff_root) {
            return left;
        }
        return root->val;
    }
};
