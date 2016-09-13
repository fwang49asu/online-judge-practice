class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        TreeLinkNode* upperFirst;
        TreeLinkNode* lowerFirst;
        TreeLinkNode* upper;
        TreeLinkNode* lower;
        upperFirst = upper = root;
        lowerFirst = lower = root->left == NULL ? root->right : root->left;
        while(lowerFirst != NULL) {
            while(lower != NULL) {
                TreeLinkNode* next = NULL;
                // find the next
                if(upper->left == lower && upper->right != NULL) {
                    next = upper->right;
                } else {
                    upper = upper->next;
                    while(upper != NULL) {
                        if(upper->left != NULL) {
                            next = upper->left;
                            break;
                        }
                        if(upper->right != NULL) {
                            next = upper->right;
                            break;
                        }
                        upper = upper->next;
                    }
                }
                lower->next = next;
                lower = next;
            }
            upperFirst = lowerFirst;
            lowerFirst = NULL;
            while(upperFirst != NULL) {
                if(upperFirst->left != NULL) {
                    lowerFirst = upperFirst->left;
                    break;
                }
                if(upperFirst->right != NULL) {
                    lowerFirst = upperFirst->right;
                    break;
                }
                upperFirst = upperFirst->next;
            }
            upper = upperFirst;
            lower = lowerFirst;
        }
    }
};
