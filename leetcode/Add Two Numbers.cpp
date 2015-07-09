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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int tmp=(l1->val+l2->val)%10;
        int carry=(l1->val+l2->val)/10;
        ListNode *nh=new ListNode(tmp);
        ListNode *cur=nh;
        ListNode *cur1=l1->next;
        ListNode *cur2=l2->next;
        while(cur1!=NULL&&cur2!=NULL){
            tmp=(cur1->val+cur2->val+carry)%10;
            carry=(cur1->val+cur2->val+carry)/10;
            ListNode *t=new ListNode(tmp);
            cur->next=t;
            cur=cur->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        if(cur1==NULL&&cur2==NULL){
            if(carry!=0)
                cur->next=new ListNode(carry);
        }
        else{
            if(cur2!=NULL){
                while(cur2!=NULL){
                    tmp=(cur2->val+carry)%10;
                    carry=(cur2->val+carry)/10;
                    cur->next=new ListNode(tmp);
                    cur=cur->next;
                    cur2=cur2->next;
                }
                if(carry!=0)
                    cur->next=new ListNode(carry);
            }
            else{
                while(cur1!=NULL){
                    tmp=(cur1->val+carry)%10;
                    carry=(cur1->val+carry)/10;
                    cur->next=new ListNode(tmp);
                    cur=cur->next;
                    cur1=cur1->next;
                }
                if(carry!=0)
                    cur->next=new ListNode(carry);              
            }
        }
        return nh;
    }
};

//mind the corner cases