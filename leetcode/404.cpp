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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        if(root->left != NULL) {
            if(root->left->left == NULL && root->left->right == NULL) {
                result += root->left->val;
            } else {
                result += sumOfLeftLeaves(root->left);
            }
        }
        result += sumOfLeftLeaves(root->right);
        return result;
    }
};
