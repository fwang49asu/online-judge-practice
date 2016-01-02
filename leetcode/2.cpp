class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* cur = result;
        ListNode* prev = NULL;
        int carry = 0;
        while(NULL != l1 || NULL != l2 || carry > 0) {
            if(NULL == cur) {
                prev->next = cur = new ListNode(0);
            }
            int val_1 = NULL == l1 ? 0: l1->val;
            int val_2 = NULL == l2 ? 0: l2->val;
            int val = val_1 + val_2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->val = val;
            l1 = NULL == l1 ? NULL : l1->next;
            l2 = NULL == l2 ? NULL : l2->next;
            prev = cur;
            cur = cur->next;
        }
        return result;
    }
};
