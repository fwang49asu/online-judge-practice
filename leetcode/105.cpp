#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildTree(preorder, 0, n-1, inorder, 0, n-1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int prelow, int prehigh, vector<int>& inorder, int inlow, int inhigh) {
        if(prehigh < prelow) {
            return NULL;
        }
        int v = preorder[prelow];
        TreeNode* root = new TreeNode(v);
        int middlePos = inlow;
        for(; inorder[middlePos] != v; ++middlePos);
        int leftLength = middlePos - inlow;
        root->left = buildTree(preorder, prelow+1, prelow+leftLength, inorder, inlow, middlePos - 1);
        root->right = buildTree(preorder, prelow+leftLength+1, prehigh, inorder, middlePos+1, inhigh);
        return root;
    }
};
