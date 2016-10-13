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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right;
        ListNode* tail;
        ListNode* cur;
        if(fast->next != NULL) {
            slow = slow->next;
        }
        right = slow->next;
        slow->next = NULL;
        tail = reverse(right);
        for(cur = tail; cur!=NULL; cur=cur->next, head = head->next) {
            if(head->val != cur->val) {
                right = reverse(tail);
                slow->next = right;
                return false;
            }
        }
        right = reverse(tail);
        slow->next = right;
        return true;
    }
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(next != NULL) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};
