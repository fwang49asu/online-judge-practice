class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
            return;
        }
        queue<TreeLinkNode*> cur;
        queue<TreeLinkNode*> next;
        TreeLinkNode* prev = NULL;
        cur.push(root);
        while(!cur.empty()) {
            TreeLinkNode* node = cur.front();
            cur.pop();
            if(prev != NULL) {
                prev->next = node;
            }
            prev = node;
            if(node->left != NULL) {
                next.push(node->left);
            }
            if(node->right != NULL) {
                next.push(node->right);
            }
            if(cur.empty()) {
                cur.swap(next);
                prev = NULL;
            }
        }
    }
};