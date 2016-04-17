#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

void print(ListNode* p) {
    if(p == NULL) {
        cout << endl;
        return;
    }
    cout << p->val << "\t";
    print(p->next);
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            ListNode* cur = head;
            while(cur != NULL) {
                if(cur->next == NULL || cur->val != cur->next->val) {
                    cur = cur->next;
                } else {
                    ListNode* temp = cur->next;
                    cur->next = cur->next->next;
                    temp->next = NULL;
                    delete temp;
                }
            }
            return head;
        }
};

int main() {
    ListNode* cur = new ListNode(2);
    cur = new ListNode(1, cur);
    cur = new ListNode(1, cur);

    print(cur);
    Solution s;
    cur = s.deleteDuplicates(cur);
    print(cur);
    while(cur != NULL) {
        ListNode* p = cur->next;
        delete cur;
        cur = p;
    }
    return 0;
}
