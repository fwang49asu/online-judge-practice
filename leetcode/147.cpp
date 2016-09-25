class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
       if(head == NULL) {
            return NULL;
        }
        ListNode* pre = head;
        while(pre->next != NULL) {
            if(pre->val > pre->next->val) {
                ListNode* cur = pre->next;
                pre->next = cur->next;
                // insert it
                if(head->val > cur->val) {
                    cur->next = head;
                    head = cur;
                } else {
                    ListNode* p = head;
                    while(p->next->val <= cur->val) {
                        p = p->next;
                    }
                    cur->next = p->next;
                    p->next = cur;
                }
            } else {
                pre = pre->next;
            }
        }
        return head;
    }
};
