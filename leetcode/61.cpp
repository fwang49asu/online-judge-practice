#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* list) {
    for(; NULL != list; list = list->next) {
        cout << list->val << "\t";
    }
    cout << endl;
}

void destroyList(ListNode* list) {
    if(NULL != list) {
        destroyList(list->next);
    }
    delete list;
}

ListNode* createList(int* data, int length) {
    ListNode* result = NULL;
    for(int i=length - 1; i>=0; --i) {
        ListNode* temp = new ListNode(data[i]);
        temp->next = result;
        result = temp;
    }
    return result;
}

class Solution {
    public:
        ListNode *rotateRight(ListNode* head, int k) {
            int n = length(head);
            if(n == 0) {
                return head;
            }
            k = k % n;
            ListNode* front = head;
            ListNode* end = head;
            for(int i=0; i<k && NULL != end; ++i, end = end->next) ;
            if(NULL == end) {
                return head;
            }
            for(; end->next != NULL; front = front->next, end = end->next) ;
            cout << end->val << endl;
            end->next = head;
            head = front->next;
            front->next = NULL;
            return head;
        }
        int length(ListNode* list) {
            if(NULL == list) {
                return 0;
            }
            return length(list->next) + 1;
        }
};

int main() {
    int data[] = {1, 2, 3, 4, 5};
    ListNode* list = createList(data, 2);
    Solution s;
    list = s.rotateRight(list, 3);
    printList(list);
    destroyList(list);
    return 0;
}
