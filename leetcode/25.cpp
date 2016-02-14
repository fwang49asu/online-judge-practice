#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode() {
        if(next != NULL) {
            delete next;
        }
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) {
            return head;
        }
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        
        while(p != NULL) {
            p = reverseNextK(p, k);
        }
        
        p = head->next;
        delete head;
        return p;
    }
private:
    ListNode* reverseNextK(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* result = head->next;
        for(int i=0; i<k; ++i) {
            if(tail == NULL) {
                return NULL;
            }
            tail = tail->next;
        }
        if(tail == NULL) {
            return NULL;
        }
        ListNode* boundary = tail->next;
        ListNode* current = head->next;
        ListNode* prev = boundary;
        ListNode* next = NULL;
        while(current != boundary) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = prev;
        return result;
    }
};
