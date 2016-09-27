#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* p) {
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        // find the center
        ListNode* slow = head;
        ListNode* fast = head;
        for(;fast->next != NULL && fast->next->next != NULL; slow = slow->next, fast=fast->next->next);
        ListNode* odd = fast->next == NULL ? slow : NULL;
        ListNode* tail = slow->next;
        slow->next = NULL;
        tail = Reverse(tail);
        if(odd != NULL) {
            Reverse(head);
            slow = slow->next;
            odd->next = NULL;
            Reverse(slow);
        }

        while(head->next != NULL) {
            ListNode* next = head->next;
            ListNode* tail_next = tail->next;
            head->next = tail;
            tail->next = next;
            tail = tail_next;
            head = next;
        }

        head->next = tail;
        tail->next = odd;
    }
private:
    ListNode* Reverse(ListNode* head) {
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

int main() {
    vector<ListNode*> vec;
    int n = 3;
    for(int i=1; i<=n; ++i) {
        vec.push_back(new ListNode(i));
    }
    for(int i=1; i<n; ++i) {
        vec[i-1]->next = vec[i];
    }

    Solution s;
    s.reorderList(vec[0]);
    print(vec[0]);

    for(ListNode* p: vec) {
        delete p;
    }
    return 0;
}
