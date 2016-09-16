class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL) {
            return result;
        }
        vector<int> buffer;
        dfs(root, buffer, result);
        return result;
    }
private:
    void dfs(TreeNode* root, vector<int>& buffer, vector<string>& result) {
        if(root->left == NULL && root->right == NULL) {
            buffer.push_back(root->val);
            result.push_back(helper(buffer));
            buffer.pop_back();
            return;
        }
        buffer.push_back(root->val);
        if(root->left != NULL) {
            dfs(root->left, buffer, result);
        }
        if(root->right != NULL) {
            dfs(root->right, buffer, result);
        }
        buffer.pop_back();
    }
    string helper(vector<int>& buffer) {
        int len = buffer.size()-1;
        stringstream ss;

        for(int i=0; i<len; ++i) {
            ss << buffer[i] << "->";
        }
        ss << buffer[len];
        return ss.str();
    }
};
