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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* prev_a = headA;
        ListNode* prev_b = headB;
        ListNode* cur_a = headA->next;
        ListNode* cur_b = headB->next;

        int x_1 = 1;
        while(cur_a != NULL) {
            prev_a = cur_a;
            cur_a = cur_a->next;
            ++x_1;
        }

        int x_2 = 1;
        while(cur_b != NULL) {
            prev_b = cur_b;
            cur_b = cur_b->next;
            ++x_2;
        }

        if(prev_a != prev_b) {
            return NULL;
        }

        ListNode* tail = Reverse(headB);
        int x_3 = Length(headA);
        int a = (x_1 - x_2 + x_3 - 1) >> 1;

        cur_a = headA;
        for(int i=0; i<a; ++i) {
            cur_a = cur_a->next;
        }
        ListNode* result = cur_a;
        Reverse(tail);
        return result;
    }
private:
    ListNode* Reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
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
    int Length(ListNode* head) {
        int result = 0;
        while(head != NULL) {
            ++result;
            head = head->next;
        }
        return result;
    }
};
