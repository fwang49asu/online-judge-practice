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
    ListNode *merge(ListNode *n1, ListNode *n2){
        ListNode *nh=new ListNode(-1);
        ListNode *cur=nh;
        while(1){
            if(n1==NULL){
                cur->next=n2;
                break;
            }
            if(n2==NULL){
                cur->next=n1;
                break;
            }
            if(n1->val<n2->val){
                cur->next=n1;
                n1=n1->next;
            }
            else{
                cur->next=n2;
                n2=n2->next;
            }
            cur=cur->next;
        }
        return nh->next;
    }
    void split(ListNode *root, ListNode** a, ListNode** b){
        ListNode *slow,*fast;
        if(root==NULL||root->next==NULL){
            *a=root;
            *b=NULL;
            return;
        }
        else{
            slow=root;
            fast=root;
            while(fast&&fast->next){
                fast=fast->next->next;
                if(!fast)
                    break;
                slow=slow->next;
            }
            *a=root;
            *b=slow->next;
            slow->next=NULL;
        }
    }
    void mergeSort(ListNode** head){
        ListNode *cur=*head;
        ListNode *a,*b;
        if(cur==NULL||cur->next==NULL)
            return;
        split(cur,&a,&b);
        mergeSort(&a);
        mergeSort(&b);
        *head=merge(a,b);
    }
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};