#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int direction = 1;
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode*> curQ;
        queue<TreeNode*> nextQ;
        vector<int> vec;
        curQ.push(root);
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
                curQ.swap(nextQ);
                queue<TreeNode*> q;
                nextQ.swap(q);
                if(direction == 0) {
                    int n = vec.size();
                    int half = n/2;
                    for(int i=0; i<half; ++i) {
                        int t = vec[i];
                        vec[i] = vec[n-1-i];
                        vec[n-1-i] = t;
                    }
                }
                direction = direction ^ 1;
                vector<int> tvec;
                tvec.swap(vec);
                result.push_back(tvec);
            }
        }
        return result;
    }
};
