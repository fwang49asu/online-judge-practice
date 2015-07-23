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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int level=1;
        queue<TreeNode *> curlevel;
        queue<TreeNode *> nextlevel;
        curlevel.push(root);
        while(!curlevel.empty()){
            while(!curlevel.empty()){
                TreeNode *tmp=curlevel.front();
                curlevel.pop();
                if(tmp->left==NULL&&tmp->right==NULL)
                    return level;
                else{
                    if(tmp->left)
                        nextlevel.push(tmp->left);
                    if(tmp->right)
                        nextlevel.push(tmp->right);
                }
            }
            swap(curlevel,nextlevel);
            level++;
        }
        return level;
    }
};