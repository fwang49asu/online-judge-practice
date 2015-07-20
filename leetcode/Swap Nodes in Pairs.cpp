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
    ListNode* swapPairs(ListNode* head) {
        ListNode *nh=new ListNode(-1);
        nh->next=head;
        ListNode *cur=nh;
        while(cur&&cur->next&&cur->next->next){
            ListNode *p=cur->next;
            ListNode *n=cur->next->next;
            p->next=n->next;
            n->next=p;
            cur->next=n;
            cur=p;
        }
        return nh->next;
    }
};