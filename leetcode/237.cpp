class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL) {
            return;
        }
        ListNode* next = node->next;
        ListNode* fast = node->next->next;
        while(fast != NULL) {
            node->val = next->val;
            node = node->next;
            next = next->next;
            fast = fast->next;
        }
        node->val = next->val;
        delete next;
        node->next = NULL;

    }
};
