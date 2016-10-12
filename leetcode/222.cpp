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
    int countNodes(TreeNode* root) {
        TreeNode *left_p = root;
        TreeNode *right_p = root;
        int left_height = 0;
        int right_height = 0;
        while(left_p!=NULL) {
            ++left_height;
            left_p = left_p->left;
        }
        while(right_p!=NULL) {
            ++right_height;
            right_p = right_p->right;
        }
        if(left_height == right_height) {
            return (1 << left_height) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
