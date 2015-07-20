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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return false;
        ListNode *p=head->next,*np=head->next->next;
        while(np&&np->next){
            if(p==np)
                return true;
            p=p->next;
            np=np->next->next;
        }
        return false;
    }
};