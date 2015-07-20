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
    bool find(TreeNode *root, TreeNode *target){
        if(root==NULL)
            return false;
        if(root==target)
            return true;
        bool lf=find(root->left,target);
        bool rf=find(root->right,target);
        return lf||rf;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q)
            return root;
        if(find(root->left,p)&&find(root->right,q)||find(root->left,q)&&find(root->right,p))
            return root;
        else if(find(root->left,p)&&find(root->left,q))
            return lowestCommonAncestor(root->left,p,q);
        else
            return lowestCommonAncestor(root->right,p,q);
    }
};