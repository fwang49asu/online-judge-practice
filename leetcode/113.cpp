#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        vector<int> buffer;
        helper(root, sum, result, buffer);
        return result;
    }
private:
    void helper(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& buffer) {
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) {
                vector<int> vec;
                for(int i=0; i<buffer.size(); ++i) {
                    vec.push_back(buffer[i]);
                }
                vec.push_back(root->val);
                result.push_back(vec);
                return;
            } else {
                return;
            }
        }
        if(root->left == NULL) {
            buffer.push_back(root->val);
            helper(root->right, sum - root->val, result, buffer);
            buffer.pop_back();
            return;
        }
        if(root->right == NULL) {
            buffer.push_back(root->val);
            helper(root->left, sum - root->val, result, buffer);
            buffer.pop_back();
            return;
        }
        buffer.push_back(root->val);
        helper(root->left, sum - root->val, result, buffer);
        helper(root->right, sum - root->val, result, buffer);
        buffer.pop_back();
    }
};
