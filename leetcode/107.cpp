#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> curQ;
        queue<TreeNode*> nextQ;
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        
        curQ.push(root);
        vector<int> vec;
        while(!curQ.empty()) {
            TreeNode* p = curQ.front();
            curQ.pop();
            vec.push_back(p->val);
            if(p->left != NULL) {
                nextQ.push(p->left);
            }
            if(p->right != NULL) {
                nextQ.push(p->right);
            }
            if(curQ.empty()) {
                nextQ.swap(curQ);
                vector<int> v;
                v.swap(vec);
                result.push_back(v);
            }
        }
        
        int n = result.size();
        int half = n/2;
        for(int i=0; i<half; ++i) {
            swap(result[i], result[n-1-i]);
        }
        return result;
    }
};
