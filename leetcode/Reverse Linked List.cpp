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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *cur,*next,*prev;
        cur=head;
        next=NULL;
        prev=head->next;
        while(prev){
            cur->next=next;
            next=cur;
            cur=prev;
            prev=prev->next;
        }
        cur->next=next;
        return cur;
    }
};