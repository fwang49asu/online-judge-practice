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
    void dfs(vector<vector<int>>& res, TreeNode *root, int sum, vector<int>& line){
        if(root->left==NULL&&root->right==NULL){
            if(root->val==sum){
                line.push_back(root->val);
                res.push_back(line);
                line.pop_back();
            }
            return;
        }
        if(root->left!=NULL){
            line.push_back(root->val);
            dfs(res,root->left,sum-root->val,line);
            line.pop_back();
        }
        if(root->right!=NULL){
            line.push_back(root->val);
            dfs(res,root->right,sum-root->val,line);
            line.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> line;
        if(root==NULL)
            return res;
        dfs(res,root,sum,line);
        return res;
    }
};