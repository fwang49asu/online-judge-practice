class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() -1);
    }
private:
    TreeNode* build(vector<int>& nums, int low, int high) {
        if(low > high) {
            return NULL;
        }
        int middle = (low + high) >> 1;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = build(nums, low, middle-1);
        root->right = build(nums, middle+1, high);
        return root;
    }
};
