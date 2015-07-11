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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *prev=head->next,*cur=head->next->next;
        while(cur!=NULL&&cur->next!=NULL){
            if(prev==cur)
                break;
            prev=prev->next;
            cur=cur->next->next;
        }
        if(prev!=cur)
            return NULL;
        cur=head;
        while(cur!=prev){
            cur=cur->next;
            prev=prev->next;
        }
        return cur;
    }
};