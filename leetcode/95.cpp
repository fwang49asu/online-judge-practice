#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            vector<TreeNode*> vec;
            return vec;
        }
        vector<vector<TreeNode*>> buffer;
        {
            vector<TreeNode*> vec;
            vec.push_back(NULL);
            buffer.push_back(vec);
        }
        for(int i=1; i<=n; ++i) {
            vector<TreeNode*> vec;
            for(int k=1; k<=i; ++k) {
                vector<TreeNode*>& left = buffer[k-1];
                vector<TreeNode*>& right = buffer[i-k];
                for(int x=0; x<left.size(); ++x) {
                    for(int y=0; y<right.size(); ++y) {
                        TreeNode* root = new TreeNode(k);
                        root->left = clone(left[x], 0);
                        root->right = clone(right[y], k);
                        vec.push_back(root);
                    }
                }
            }
            buffer.push_back(vec);
        }
        for(int i=1; i<n; ++i) {
            vector<TreeNode*>& vec = buffer[i];
            for(int k=0; k<vec.size(); ++k) {
                freeNode(vec[k]);
            }
        }
        return buffer[n];
    }
    TreeNode* clone(TreeNode* root, int offset) {
        if(root == NULL) {
            return NULL;
        }
        TreeNode* result = new TreeNode(root->val + offset);
        result->left = clone(root->left, offset);
        result->right = clone(root->right, offset);
        return result;
    }
    void freeNode(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        freeNode(root->left);
        freeNode(root->right);
        delete root;
    }
};
