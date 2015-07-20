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
    bool isSubTreeValid(TreeNode *root, double lb, double rb){
        bool lv=true;
        bool rv=true;
        if(root->val<=lb||root->val>=rb)
            return false;
        if(root->left){
            lv=isSubTreeValid(root->left,lb,root->val);
        }
        if(root->right){
            rv=isSubTreeValid(root->right,root->val,rb);
        }
        return lv&&rv;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool lv=true;
        bool rv=true;
        if(root->left)
            lv=isSubTreeValid(root->left,LONG_MIN,root->val);
        if(root->right)
            rv=isSubTreeValid(root->right,root->val,LONG_MAX);
        return lv&&rv;
    }
};