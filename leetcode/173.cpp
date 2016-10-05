/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root!=NULL) {
            state_stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !state_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* root = state_stack.top();
        int result = root->val;
        // find next
        state_stack.pop();
        if(root->right != NULL) {
            root = root->right;
            while(root != NULL) {
                state_stack.push(root);
                root = root->left;
            }
        }
        return result;
    }
private:
    stack<TreeNode*> state_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
