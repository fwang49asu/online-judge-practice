/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p = NodeInCycle(head);
        if(p == NULL) {
            return NULL;
        }
        if(p == p->next) {
            return p;
        }
        ListNode* next = p->next;
        p->next = NULL;
        int y = length(next);
        int a = length(head);
        reverse(head);
        int b = length(next);
        reverse(p);
        p->next = next;
        int x = (a + b - y - 1) / 2;
        p = head;
        for(int i=0; i<x; ++i) {
            p = p->next;
        }
        return p;
    }
private:
    int length(ListNode* head) {
        if(head == NULL) {
            return 0;
        }
        int result = 0;
        while(head != NULL) {
            ++result;
            head = head->next;
        }
        return result;
    }
    ListNode* reverse(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(next != NULL) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
    ListNode* NodeInCycle(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }
        return slow;
    }
};
