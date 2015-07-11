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
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int rootloc){
        if(start==end)
            return new TreeNode(inorder[start]);
        TreeNode *root=new TreeNode(postorder[rootloc]);
        int loc=0;
        while(inorder[loc]!=root->val)
            loc++;
        if(loc>start)
            root->left=buildSubTree(inorder,postorder,start,loc-1,rootloc-(end-loc+1));//rootloc-rightlenth-1=leftrootloc
        if(loc<end)
            root->right=buildSubTree(inorder,postorder,loc+1,end,rootloc-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0)
    		return NULL;
        int n=inorder.size();
        TreeNode *root=new TreeNode(postorder[n-1]);
        int loc=0;
        while(inorder[loc]!=root->val)
            loc++;
        if(loc>0)
            root->left=buildSubTree(inorder,postorder,0,loc-1,loc-1);
        if(loc<n-1)
            root->right=buildSubTree(inorder,postorder,loc+1,n-1,n-2);
        return root;
    }
};