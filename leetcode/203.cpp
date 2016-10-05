class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // chop heads
        while(head != NULL && head->val == val) {
            ListNode* next = head->next;
            head->next = NULL;
            delete head;
            head = next;
        }
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = head;
        while(prev->next != NULL) {
            if(prev->next->val == val) {
                ListNode* cur = prev->next;
                prev->next = cur->next;
                cur->next = NULL;
                delete cur;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};
