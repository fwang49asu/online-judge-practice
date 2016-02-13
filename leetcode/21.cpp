#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(NULL != l1 && NULL != l2) {
            if(l2->val < l1->val) {
                swap(l1, l2);
            }
            ListNode* t = l1->next;
            p->next = l1;
            p = p->next;
            l1 = t;
        }
        if(NULL == l1) {
            p->next = l2;
        } else {
            p->next = l1;
        }
        p = head->next;
        delete head;
        return p;
    }
};
