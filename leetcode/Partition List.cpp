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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *cur,*next,*prev;
        ListNode* nh1=new ListNode(-1);
        cur=nh1;
        ListNode* nh2=new ListNode(-1);
        nh2->next=head;
        prev=nh2;
        next=nh2->next;
        while(next){
            if(next->val<x){
                ListNode *tmp=next;
                next=next->next;
                prev->next=next;
                cur->next=tmp;
                cur=cur->next;
            }
            else{
                prev=prev->next;
                next=next->next;
            }
        }
        cur->next=nh2->next;
        return nh1->next;
        
    }
};