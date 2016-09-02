#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> curQueue;
        queue<TreeNode*> nextQueue;
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        curQueue.push(root);
        vector<int> vec;
        while(!curQueue.empty()) {
            TreeNode* v = curQueue.front();
            curQueue.pop();
            vec.push_back(v->val);
            if(v->left != NULL) {
                nextQueue.push(v->left);
            }
            if(v->right != NULL) {
                nextQueue.push(v->right);
            }
            if(curQueue.empty()) {
                vector<int> tvec;
                tvec.swap(vec);
                result.push_back(tvec);
                curQueue.swap(nextQueue);
                queue<TreeNode*> emptyQ;
                nextQueue.swap(emptyQ);
            }
        }
        return result;
    }
};
