class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, NULL);
    }
    TreeNode* build(ListNode* low, ListNode* high) {
        if(low == high) {
            return NULL;
        }
        ListNode* slow = low;
        ListNode* fast = low;
        while(fast != high && fast->next != high) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(low, slow);
        root->right = build(slow->next, high);
        return root;
    }
};
