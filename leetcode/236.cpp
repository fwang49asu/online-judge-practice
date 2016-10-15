/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, int>> p_vec;
        vector<pair<TreeNode*, int>> q_vec;
        dfs(root, p_vec, p);
        dfs(root, q_vec, q);
        int n = min(p_vec.size(), q_vec.size());
        int i = 0;
        for(i=0; i<n && p_vec[i].first == q_vec[i].first; ++i);
        return p_vec[i-1].first;
    }
private:
    void dfs(TreeNode* root, vector<pair<TreeNode*, int>>& path, TreeNode* target) {
        path.push_back(make_pair(root, 0));
        while(path.back().first != target) {
            pair<TreeNode*, int>& t = path[path.size() - 1];
            if(t.second == 0) {
                ++t.second;
                if(t.first->left != NULL) {
                    path.push_back(make_pair(t.first->left, 0));
                    continue;
                }
            }
            if(t.second == 1) {
                ++t.second;
                if(t.first->right != NULL) {
                    path.push_back(make_pair(t.first->right, 0));
                    continue;
                }
            }
            if(t.second == 2) {
                path.pop_back();
            }
        }
    }
};
