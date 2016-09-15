class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != NULL && fast != NULL) {
            if(slow == fast) {
                return true;
            }
            if(slow->next == NULL || fast->next == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
