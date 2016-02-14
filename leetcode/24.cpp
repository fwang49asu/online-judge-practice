#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next) {
            return head;
        }
        ListNode* result = head->next;
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* third = NULL;
        ListNode* fourth = NULL;
        while(first != NULL && second != NULL) {
            third = second->next;
            second->next = first;
            if(third == NULL) {
                first->next = NULL;
                second = NULL;
            } else if(third->next == NULL) {
                first->next = third;
                first = NULL;
            } else {
                first->next = third->next;
                first = third;
                second = third->next;
            }
        }
        return result;
    }
};
