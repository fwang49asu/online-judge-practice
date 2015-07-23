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
private:
    vector<int> res;
    int index;
public:
    BSTIterator(TreeNode *root) {
        index=0;
        stack<TreeNode*> s;
        if(root==NULL)
            return;
        s.push(root);
        while(!s.empty()){
            TreeNode *tmp=s.top();
            s.pop();
            if(tmp->right){
                s.push(tmp->right);
                tmp->right=NULL;
            }
            if(!tmp->left&&!tmp->right)
                res.push_back(tmp->val);
            if(tmp->left){
                TreeNode *t=tmp->left;
                tmp->left=NULL;
                s.push(tmp);
                s.push(t);
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<res.size();
    }

    /** @return the next smallest number */
    int next() {
        return res[index++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */