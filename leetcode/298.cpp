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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 1;
        longestConsecutive(root, root->val-1, 0, result);
        return result;
    }
    void longestConsecutive(TreeNode* root, int prev, int cur_count, int& result) {
        if(root == NULL) {
            result = max(result, cur_count);
            return;
        }
        if(root->val == (prev+1)) {
            result = max(result, cur_count+1);
            longestConsecutive(root->left, root->val, cur_count+1, result);
            longestConsecutive(root->right, root->val, cur_count+1, result);
        } else {
            longestConsecutive(root->left, root->val, 1, result);
            longestConsecutive(root->right, root->val, 1, result);
        }
    }
};
