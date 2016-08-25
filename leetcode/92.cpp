#include <iostream>

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

ListNode* createList(int n) {
    ListNode* head = NULL;
    while(n >= 1) {
        ListNode* p = new ListNode(n);
        p->next = head;
        head = p;
        --n;
    }
    return head;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(m == n) {
                return head;
            }
            // make a dummy head
            ListNode* p = new ListNode(0);
            p->next = head;
            head = p;
            ListNode* pre[2];
            --m;
            --n;
            pre[0] = pre[1] = head;
            for(int i=0; i<m; ++i) {
                pre[0] = pre[0]->next;
            }
            for(int i=0; i<n; ++i) {
                pre[1] = pre[1]->next;
            }

            ListNode* after = pre[1]->next->next;
            pre[1]->next->next = NULL;

            ListNode* last = pre[0]->next;
            pre[0]->next = reverse(last);
            last->next = after;

            // chop off the dummy head
            p = head->next;
            head->next = NULL;
            delete head;
            return p;
        }
        ListNode* reverse(ListNode* head) {
            ListNode* p = new ListNode(0);
            p->next = head;

            ListNode* pre = p;
            ListNode* cur = pre->next;
            ListNode* next = cur->next;

            while(next != NULL) {
                cur->next = pre;
                pre = cur;
                cur = next;
                next = next->next;
            }
            cur->next = pre;

            head->next = NULL;
            p->next = NULL;
            delete p;
            return cur;
        }
};

int main() {
    int n;
    ListNode* head = createList(3);
    print(head);
    Solution s;
    head = s.reverseBetween(head, 2, 3);
    print(head);
    delete head;
}
