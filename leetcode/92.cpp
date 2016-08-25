#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
            ListNode* post[2];
            ListNode* current[2];
            --m;
            --n;
            pre[0] = pre[1] = head;
            for(int i=0;i<m; ++m) {
                pre[0] = pre[0]->next;
            }
            for(int i=0;i<n; ++m) {
                pre[1] = pre[1]->next;
            }
            while((n-m) > 1) {
                current[0] = pre[0]->next;
                current[1] = pre[1]->next;
                post[0] = current[0]->next;
                post[1] = current[0]->next;
                current[0]->next = post[1];
                current[1]->next = post[0];
                pre[0]->next = current[1];

                
                ++m;
                --n;
            }
            // chop off the dummy head
            p = head->next;
            delete head;
            return p;
        }
}
