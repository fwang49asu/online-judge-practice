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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL) {
            return NULL;
        }
        vector<TreeNode*> vec;
        TreeNode* cur = root;
        while(cur != p) {
            vec.push_back(cur);
            if(p->val < cur->val) {
                cur = cur->left;
            } else if(p->val > cur->val) {
                cur = cur->right;
            }
        }
        vec.push_back(cur);
        if(cur->right != NULL) {
            cur = cur->right;
            while(cur->left != NULL) {
                vec.push_back(cur);
                cur = cur->left;
            }
            return cur;
        }
        vec.pop_back();
        while(!vec.empty() && vec.back()->right == cur) {
            cur = vec.back();
            vec.pop_back();
        }
        if(vec.empty()) {
            return NULL;
        }
        return vec.back();
    }
};
