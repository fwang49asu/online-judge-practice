#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        for(int i=0; i<n; ++i) {
            p = p->next;
        }
        if(NULL == p) {
            // delete head
            p = head->next;
            delete head;
            return p;
        }
        ListNode* pre = head;
        while(NULL != p->next) {
            p = p->next;
            pre = pre->next;
        }
        p = pre->next;
        pre->next = pre->next->next;
        delete p;
        return head;
    }
};
