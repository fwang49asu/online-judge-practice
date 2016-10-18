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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        TreeNode* start = ClosestNode(root, target);
        vector<TreeNode*> left_stack;
        BuildStack(root, start, left_stack);
        vector<TreeNode*> right_stack(left_stack.begin(), left_stack.end());
        vector<int> result;
        result.push_back(start->val);
        TreeNode* larger_node = NULL;
        TreeNode* smaller_node = NULL;
        while(result.size() < k) {
            if(larger_node == NULL) {
                larger_node = LargerNode(right_stack);
            }
            if(smaller_node == NULL) {
                smaller_node = SmallerNode(left_stack);
            }
            if(larger_node == NULL) {
                result.push_back(smaller_node->val);
                smaller_node = NULL;
                continue;
            }
            if(smaller_node == NULL) {
                result.push_back(larger_node->val);
                larger_node = NULL;
                continue;
            }
            if(abs(smaller_node->val - target) < abs(larger_node->val - target)) {
                result.push_back(smaller_node->val);
                smaller_node = NULL;
            } else {
                result.push_back(larger_node->val);
                larger_node = NULL;
            }
        }
        return result;
    }
private:
    TreeNode* ClosestNode(TreeNode* root, double target) {
        if(target == root->val) {
            return root;
        }
        if(target < root->val) {
            if(root->left == NULL) {
                return root;
            }
            TreeNode* left = ClosestNode(root->left, target);
            if(abs(left->val - target) < abs(root->val - target)) {
                return left;
            }
            return root;
        }
        if(root->right == NULL) {
            return root;
        }
        TreeNode* right = ClosestNode(root->right, target);
        if(abs(right->val - target) < abs(root->val - target)) {
            return right;
        }
        return root;
    }
    void BuildStack(TreeNode* root, TreeNode* target, vector<TreeNode*>& vec) {
        vec.push_back(root);
        while(vec.back() != target) {
            if(target->val < vec.back()->val) {
                vec.push_back(vec.back()->left);
            } else {
                vec.push_back(vec.back()->right);
            }
        }
    }
    TreeNode* LargerNode(vector<TreeNode*>& vec) {
        if(vec.empty()) {
            return NULL;
        }
        if(vec.back()->right != NULL) {
            vec.push_back(vec.back()->right);
            while(vec.back()->left != NULL) {
                vec.push_back(vec.back()->left);
            }
            return vec.back();
        }
        TreeNode* cur = vec.back();
        vec.pop_back();
        while(!vec.empty() && vec.back()->right == cur) {
            cur = vec.back();
            vec.pop_back();
        }
        return vec.empty() ? NULL : vec.back();
    }
    TreeNode* SmallerNode(vector<TreeNode*>& vec) {
        if(vec.empty()) {
            return NULL;
        }
        if(vec.back()->left != NULL) {
            vec.push_back(vec.back()->left);
            while(vec.back()->right != NULL) {
                vec.push_back(vec.back()->right);
            }
            return vec.back();
        }
        TreeNode* cur = vec.back();
        vec.pop_back();
        while(!vec.empty() && vec.back()->left == cur) {
            cur = vec.back();
            vec.pop_back();
        }
        return vec.empty() ? NULL : vec.back();
    }
};
