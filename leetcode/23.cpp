#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    class mycomparison {
        public:
        bool operator() (ListNode*& left, ListNode*& right) const {
            return left->val > right->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // make a min heap
        priority_queue<ListNode*,vector<ListNode*>, mycomparison> minheap;
        for(ListNode* p: lists) {
            if(NULL != p) {
                minheap.push(p);
            }
        }
        
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(!minheap.empty()) {
            ListNode* p = minheap.top();
            cur->next = p;
            cur = cur->next;
            p = p->next;
            minheap.pop();
            if(NULL != p) {
                minheap.push(p);
            }
        }
        cur = head->next;
        delete head;
        return cur;
    }
};
