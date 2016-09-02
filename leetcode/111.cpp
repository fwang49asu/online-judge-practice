class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        stack<TreeNode*> cur;
        stack<TreeNode*> next;
        cur.push(root);
        int result = 1;
        while(!cur.empty()) {
            TreeNode* p = cur.top();
            cur.pop();
            if(p->left == NULL && p->right == NULL) {
                return result;
            }
            if(p->left != NULL) {
                next.push(p->left);
            }
            if(p->right != NULL) {
                next.push(p->right);
            }
            if(cur.empty()) {
                cur.swap(next);
                ++result;
            }
        }
        return result;
    }
};
