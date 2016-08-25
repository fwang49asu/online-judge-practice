#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        stack<TreeNode*> leftStack;
        void pushLeftPath(TreeNode* root) {
            while(root != NULL) {
                leftStack.push(root);
                root = root->left;
            }
        }
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            pushLeftPath(root);
            while(!leftStack.empty()) {
                TreeNode* cur = leftStack.top();
                leftStack.pop();
                result.push_back(cur->val);
                pushLeftPath(cur->right);
            }
            return result;
        }
};
