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
    vector<TreeNode *> dfs(int start, int end){
        vector<TreeNode *> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode *> lres=dfs(start,i-1);
            vector<TreeNode *> rres=dfs(i+1,end);
            for(int j=0;j<lres.size();j++){
                for(int k=0;k<rres.size();k++){
                    TreeNode *tmp=new TreeNode(i);
                    tmp->left=lres[j];
                    tmp->right=rres[k];
                    res.push_back(tmp);
                }
            }
        }
        return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};