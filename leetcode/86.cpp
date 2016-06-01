#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            // fake heads for left and right
            ListNode* leftHead = new ListNode(0);
            ListNode* rightHead = new ListNode(0);
            ListNode* leftTail = leftHead;
            ListNode* rightTail = rightHead;
            ListNode* p;
            // put the nodes to the lists
            while(head != NULL) {
                // chop off head
                p = head;
                head = head->next;
                p->next = NULL;
                if(p->val < x) {
                    leftTail->next = p;
                    leftTail = p;
                } else {
                    rightTail->next = p;
                    rightTail = p;
                }
            }
            // merge them
            // chop off the heads
            p = leftHead;
            leftHead = p->next;
            delete p;
            if(leftHead == NULL) {
                leftTail = NULL;
            }
            p = rightHead;
            rightHead = p->next;
            delete p;
            if(rightTail == NULL) {
                rightTail = NULL;
            }
            ListNode* result = new ListNode(0);
            ListNode* tail = result;
            if(leftHead != NULL) {
                tail->next = leftHead;
                tail = leftTail;
            }
            if(rightHead != NULL) {
                tail->next = rightHead;
            }
            p = result;
            result = result->next;
            delete p;
            return result;
        }
};

int main() {
    int array[] = {1, 4, 3, 2, 5, 2};
    int length = 6;
    ListNode* head = NULL;
    for(int i=length-1; i>=0; --i) {
        ListNode* newHead = new ListNode(array[i]);
        newHead->next = head;
        head = newHead;
    }
    print(head);
    Solution s;
    ListNode* result = s.partition(head, 3);
    print(result);
    while(result != NULL) {
        ListNode* p = result;
        result = result->next;
        delete p;
    }
    return 0;
}
