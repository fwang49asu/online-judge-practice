#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTree(inorder, 0, n-1, postorder, 0, n-1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int inlow, int inhigh, vector<int>& postorder, int postlow, int posthigh) {
        if(inlow > inhigh) {
            return NULL;
        }
        int v = postorder[posthigh];
        int middle = inlow;
        for(; inorder[middle] != v; ++middle);
        TreeNode* root = new TreeNode(v);
        root->left = buildTree(inorder, inlow, middle-1, postorder, postlow, postlow+middle-inlow-1);
        root->right = buildTree(inorder, middle+1, inhigh, postorder, postlow+middle-inlow, posthigh-1);
        return root;
    }
};
