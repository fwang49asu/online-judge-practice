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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode *fast=head,*slow=head,*prev;
        while(fast&&fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode *h=prev->next;
        prev->next=NULL;
        
        ListNode *cur=h;
        ListNode *tmp=NULL;
        ListNode *n=NULL;
        ListNode *nh=NULL;
        while(cur){
            tmp=cur->next;
            if(cur->next==NULL)
                nh=cur;
            cur->next=n;
            n=cur;
            cur=tmp;
        }
        cur=head;
        ListNode *cur1=nh;
        while(cur&&cur1){
            if(cur->val!=cur1->val)
                return false;
            cur=cur->next;
            cur1=cur1->next;
        }
        return true;
    }
};