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
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        if(root == NULL) {
            return 0;
        }
        isSubTree(root, result);
        return result;
    }
public:
    bool isSubTree(TreeNode* root, int& count) {
        if(root->left == NULL && root->right == NULL) {
            ++count;
            return true;
        }
        bool left_result = true;
        if(root->left != NULL) {
            left_result = isSubTree(root->left, count);
        }
        bool right_result = true;
        if(root->right != NULL) {
            right_result = isSubTree(root->right, count);
        }
        if(root->left != NULL && root->right == NULL
            && root->val == root->left->val && left_result) {
            ++count;
            return true;
        }
        if(root->left == NULL && root->right != NULL
            && root->val == root->right->val && right_result) {
            ++count;
            return true;
        }
        if(root->left != NULL && root->right != NULL
            && root->val == root->left->val && root->left->val == root->right->val
            && left_result && right_result) {
            ++count;
            return true;
        }
        return false;
    }
};
